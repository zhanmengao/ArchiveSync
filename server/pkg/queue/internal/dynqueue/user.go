package dynqueue

import (
	"container/list"
	"context"
	"server/pkg/queue/internal/qutil"
	"server/pkg/queue/qtyp"
	"server/pkg/util"
	"server/pkg/xlog"
	"sync"
	"sync/atomic"
	"time"
)

var (
	queueCnt       int32
	jobIncomingCnt uint64
	jobConsumeCnt  uint64
)

// userQueue 每个用户一个队列
type userQueue struct {
	sync.RWMutex               // 用于数据安全
	key          string        // 队列的key
	jobList      list.List     // 队列中的回调
	lastTime     time.Time     // 上次的最后一次入队列时间
	incoming     chan struct{} // 队列有消息
	closeing     chan struct{} // 队列退出
	wg           *sync.WaitGroup
	em           *qtyp.EventMonitor
}

func newUserQueue(ctx context.Context, key string, wg *sync.WaitGroup, em *qtyp.EventMonitor) *userQueue {
	q := &userQueue{
		key:      key,
		lastTime: time.Now(),
		incoming: make(chan struct{}, 1),
		closeing: make(chan struct{}),
		wg:       wg,
		em:       em,
	}
	q.jobList.Init()

	go q.run(ctx)

	atomic.AddInt32(&queueCnt, 1)

	return q
}

// push 往队列加入任务
func (uq *userQueue) push(job *qutil.TJob) {
	uq.Lock()
	defer uq.Unlock()
	uq.jobList.PushBack(job)
	uq.setLastTime(time.Now())
	// 尝试通知worker消费
	select {
	case uq.incoming <- struct{}{}:
	default: //do nothing
	}
}

// poll 找出所有已经入队列的任务
func (uq *userQueue) poll() []*qutil.TJob {
	uq.Lock()
	defer uq.Unlock()
	sz := uq.jobList.Len()
	tmp := make([]*qutil.TJob, 0, sz)
	for uq.jobList.Len() != 0 {
		elem := uq.jobList.Front()
		uq.jobList.Remove(elem)
		tmp = append(tmp, elem.Value.(*qutil.TJob))
	}
	return tmp
}

// run 用户队列的loop函数
func (uq *userQueue) run(ctx context.Context) {
	xlog.Debugf(ctx, "worker :%s running", uq.key)
	defer func() {
		close(uq.incoming)
		uq.closeing = nil
		uq.incoming = nil
	}()
	for {
		select {
		case <-uq.incoming:
			jobs := uq.poll()
			for _, job := range jobs {
				atomic.AddUint64(&jobConsumeCnt, 1)
				util.SafeFunc(job.Ctx, job.Func)
				uq.wg.Done()
			}
		case <-uq.closeing:
			xlog.Infof(context.Background(), "worker recieve an exit signal, key:%s", uq.key)
			atomic.AddInt32(&queueCnt, -1)
			return
		}
	}
}

func (uq *userQueue) doAllJob() {
	jobs := uq.poll()
	for _, f := range jobs {
		qtyp.Safe(f.Ctx, uq.key, f.Func, uq.em)
		uq.wg.Done()
	}
}

func (uq *userQueue) getLastTime() time.Time {
	uq.RLock()
	defer uq.RUnlock()
	return uq.lastTime
}

func (uq *userQueue) setLastTime(tm time.Time) {
	uq.lastTime = tm
}

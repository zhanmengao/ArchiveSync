package wsv2

import (
	"context"
	ws "github.com/gorilla/websocket"
	"net"
	"net/http"
	"server/pkg/global"
	"server/pkg/queue"
	"server/pkg/queue/qtyp"
	"sync"
	"time"
)

var (
	sendQueue = queue.NewQueue(context.Background(), qtyp.DefaultOption)
)

type Conn struct {
	lock        sync.Mutex
	conn        *ws.Conn
	readTimeout time.Duration
	closedCh    chan struct{} //已关闭
	connID      string
	createTime  int64
	closeTime   int64
	forwardIP   string
	remoteAddr  net.Addr
	localAddr   net.Addr
	request     *http.Request
	firstBody   []byte //首包
}

func (c *Conn) GetRealIP() string {
	return c.forwardIP
}

func (c *Conn) GetRemoteAddr() net.Addr {
	return c.remoteAddr
}

func (c *Conn) GetLocalAddr() net.Addr {
	return c.localAddr
}

func (c *Conn) GetRequest() *http.Request {
	return c.request
}
func (c *Conn) GetFirstBody() []byte {
	return c.firstBody
}

// Run 只可调用一次
func (c *Conn) Run(ctx context.Context, handler global.IHandler) (err error) {
	defer func() {
		close(c.closedCh)
	}()
	for {
		var body []byte
		body, err = c.read(ctx)
		if err != nil {
			return
		}
		if c.firstBody == nil {
			c.firstBody = body
		}
		handler.HandPacket(ctx, c, body)
	}
}

func (c *Conn) GetClosedChannel() chan struct{} {
	return c.closedCh
}

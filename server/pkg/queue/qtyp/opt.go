package qtyp

import (
	"server/pkg/xlog"
	"server/pkg/xlog/logtyp"
)

type Option struct {
	RcvEvent  QueueEventCall //队列事件的回调
	LogWrite  logtyp.Logger
	NonBlock  bool //非阻塞
	Size      int  //队列大小
	QType     QueueType
	CloseWait int64 //关闭时等待毫秒，-1为死等
}

var DefaultOption = NewOption()

func NewOption() *Option {
	return &Option{
		NonBlock:  false,
		RcvEvent:  defaultEventHandle,
		Size:      5000,
		LogWrite:  xlog.GetLogger(),
		QType:     QueueDyn,
		CloseWait: 1000,
	}
}

func (o *Option) WithNonBlock(nonBlock bool) *Option {
	o.NonBlock = nonBlock
	return o
}
func (o *Option) WithRcvEvent(e QueueEventCall) *Option {
	o.RcvEvent = e
	return o
}
func (o *Option) WithSize(sz int) *Option {
	o.Size = sz
	return o
}

func (o *Option) WithLog(l logtyp.Logger) *Option {
	o.LogWrite = l
	return o
}

func (o *Option) WithType(t QueueType) *Option {
	o.QType = t
	return o
}

func (o *Option) WithCloseWait(ms int64) *Option {
	o.CloseWait = ms
	return o
}

func defaultEventHandle(e *QueueEvent) {
	if e.Ev == EventPanic {
		xlog.Fatalf(e.Ctx, "job panic in [%s] : %s ", e.Key, e.Stack)
	} else {
		xlog.Errorf(e.Ctx, "job event [%d] in [%s] : %s ", e.Ev, e.Key, e.Stack)
	}
}

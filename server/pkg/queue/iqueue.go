package queue

import (
	"context"
	"server/pkg/queue/internal/antsqueue"
	"server/pkg/queue/internal/dynqueue"
	"server/pkg/queue/qtyp"
)

type IQueue interface {
	PushJob(ctx context.Context, key string, f func(ctx context.Context)) (err error)
	Close()
}

func NewQueue(ctx context.Context, option *qtyp.Option) (q IQueue) {
	switch option.QType {
	case qtyp.QueueQuick, qtyp.QueueDyn:
		q = dynqueue.NewDynQueue(ctx, option, qtyp.NewEventMonitor(option.RcvEvent))
	case qtyp.QueueAnts:
		q = antsqueue.NewAntsJobQueue(ctx, option, qtyp.NewEventMonitor(option.RcvEvent))
	}
	return
}

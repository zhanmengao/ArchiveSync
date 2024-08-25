package wssrv

import (
	"context"
	"server/pkg/prom"
	"time"
)

func UseOnlinePromReport(platform string, reportCD time.Duration, cb OnlineCallBack) {
	for {
		time.Sleep(reportCD)
		ctx := context.Background()
		count := 0
		prom.ReportOnline(platform, count)
		if cb != nil {
			cb(ctx, count)
		}
	}
}

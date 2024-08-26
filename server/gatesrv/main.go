package main

import (
	"github.com/gogf/gf/v2/os/gctx"
	"server/gatesrv/internal/client"
	"server/pkg/wssrv"
)

func main() {
	ctx := gctx.New()
	wsSrv := wssrv.NewWsServer(8084)
	wsSrv.UseGateway("/gate/ws", &client.Handle{})
	err := wsSrv.Start(ctx)
	if err != nil {
		panic(err)
	}
}

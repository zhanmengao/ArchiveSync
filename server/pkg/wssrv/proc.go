package wssrv

import (
	"context"
	"fmt"
	ws "github.com/gorilla/websocket"
	"net/http"
	"runtime"
	"server/pkg/xlog"
	"time"
)

func (s *WsServer) Start(ctx context.Context) (err error) {
	s.httpServer.Addr = fmt.Sprintf(":%d", s.port)
	go func() {
		err = s.httpServer.ListenAndServe()
	}()
	runtime.Gosched()
	time.Sleep(time.Duration(10) * time.Millisecond)
	xlog.Infof(ctx, "ws server start at %s ", s.httpServer.Addr)
	return
}

func (s *WsServer) UseGateway(gatewayURI string, handler IHandler) {
	s.gatewayHandler = handler
	s.gatewayURI = gatewayURI
}

func (s *WsServer) Handler(uri string, handler TUrlHandler) {
	s.lock.Lock()
	defer s.lock.Unlock()
	s.handler[uri] = handler
}

func (s *WsServer) SetReadTimeout(timeout time.Duration) {
	s.readTimeout = timeout
}

func (s *WsServer) GetReadTimeout() time.Duration {
	return s.readTimeout
}

func (s *WsServer) SetHttpServer(f func(srv *http.Server)) {
	f(s.httpServer)
}

func (s *WsServer) SetWebSocket(f func(w *ws.Upgrader)) {
	f(s.wsUpgrade)
}

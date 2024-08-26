package wssrv

import (
	"context"
	"github.com/gorilla/websocket"
	"net/http"
	"server/pkg/global"
	"server/pkg/wssrv/internal/wsv2"
	"server/pkg/xlog"
	"sync"
	"time"
)

type WsServer struct {
	httpServer     *http.Server
	port           int64
	gatewayURI     string
	gatewayHandler IHandler
	lock           sync.RWMutex
	handler        map[string]TUrlHandler
	readTimeout    time.Duration
	wsUpgrade      *websocket.Upgrader
}

func NewWsServer(port int64) *WsServer {
	srv := &WsServer{
		httpServer: &http.Server{
			WriteTimeout:   0,
			MaxHeaderBytes: 1 << 20,
		},
		port:        port,
		handler:     make(map[string]TUrlHandler),
		readTimeout: time.Duration(30) * time.Second,
		wsUpgrade: &websocket.Upgrader{
			HandshakeTimeout: 10 * time.Second,
			CheckOrigin: func(r *http.Request) bool {
				return true
			},
		},
	}
	srv.httpServer.Handler = srv
	//注册接口
	return srv
}

func (s *WsServer) ServeHTTP(writer http.ResponseWriter, request *http.Request) {
	ctx := context.Background()
	xlog.Tracef(ctx, "ServeHTTP %s ", request.RequestURI)
	switch request.URL.Path {
	case "/":
		writer.WriteHeader(http.StatusOK)
		_, _ = writer.Write([]byte("ok"))
	case s.gatewayURI:
		cli, err := s.HandleClient(ctx, writer, request)
		if err != nil {
			xlog.Warnf(ctx, "WsConn %s HandleClient err = %s", "", err)
			return
		}
		if err = cli.Run(ctx); err != nil {
			xlog.Warnf(ctx, "fClient %s Run err = %s", cli.UID, err)
			return
		}
	default:
		h, ok := s.getHandler(request.URL.Path)
		if ok {
			resPon, err := h.HandleInit(ctx, request, writer)
			if err != nil {
				xlog.Warnf(ctx, "WsConn %s HandleInit err = %s", "", err)
				return
			}
			conn, err := s.HandleWebSocket(ctx, writer, request, resPon)
			if err != nil {
				xlog.Warnf(ctx, "WsConn %s HandleWebSocket err = %s", "", err)
				return
			}
			if err = conn.Run(ctx, THandlerPacket(h.HandlePacket)); err != nil {
				xlog.Warnf(ctx, "WsConn %s run err = %s", conn.GetRealIP(), err)
				return
			}
		} else {
			writer.WriteHeader(http.StatusNotFound)
			_, _ = writer.Write([]byte("404 Not Found"))
		}
	}
	xlog.Infof(ctx, "ServeHTTP %s closed", request.RequestURI)
}

func (s *WsServer) getHandler(urlPath string) (h TUrlHandler, exist bool) {
	s.lock.RLock()
	defer s.lock.RUnlock()
	h, exist = s.handler[urlPath]
	return
}

func (s *WsServer) HandleClient(ctx context.Context, writer http.ResponseWriter, request *http.Request) (cli *Client, err error) {
	//建立连接
	wsConn, err := s.wsUpgrade.Upgrade(writer, request, nil)
	if err != nil {
		xlog.Error(ctx, "[WsConnection] Upgrade", err)
		return
	}
	cli = NewWsClient(ctx, request, wsConn, s.readTimeout, s.gatewayHandler)
	return
}

func (s *WsServer) HandleWebSocket(ctx context.Context, writer http.ResponseWriter, request *http.Request, responseHeader http.Header) (conn global.IConnect, err error) {
	//建立连接
	wsConn, err := s.wsUpgrade.Upgrade(writer, request, responseHeader)
	if err != nil {
		xlog.Error(ctx, "[WsConnection] Upgrade", err)
		return
	}
	conn = wsv2.NewWSConn(ctx, request, wsConn, s.readTimeout)
	return
}

func (s *WsServer) processWebSocket(ctx context.Context, conn global.IConnect, h TUrlHandler) {
	var err error
	defer func() {
		h.HandleClose(ctx, conn, err)
	}()
	if err = conn.Run(ctx, THandlerPacket(h.HandlePacket)); err != nil {
		xlog.Warnf(ctx, "WsConn %s run err = %s", conn.GetRealIP(), err)
		return
	}
}

package wssrv

import (
	"context"
	ws "github.com/gorilla/websocket"
	"net/http"
	"server/pb"
	"server/pkg/wssrv/internal/wsv2"
	"time"
)

type Client struct {
	UID        string
	sessionKey string
	conn       IConnect
	handler    IHandler
}

func NewWsClient(ctx context.Context, request *http.Request, conn *ws.Conn, readTimeout time.Duration, handler IHandler) *Client {
	cli := &Client{
		handler: handler,
		conn:    wsv2.NewWSConn(ctx, request, conn, readTimeout),
	}
	return cli
}

func (c *Client) HandleInit(ctx context.Context, cli *Client, sessionKey string) (uid, deviceToken string, err error) {
	//TODO implement me
	panic("implement me")
}

func (c *Client) HandleEncode(ctx context.Context, cli *Client, pkt *pb.Packet) (snd []byte, err error) {
	//TODO implement me
	panic("implement me")
}

func (c *Client) HandleDecode(ctx context.Context, cli *Client, rcv []byte) (pkt *pb.Packet, isSendToSrv bool, err error) {
	//TODO implement me
	panic("implement me")
}

func (c *Client) HandleClose(ctx context.Context, cli *Client, err error) {
	//TODO implement me
	panic("implement me")
}

func (c *Client) Run(ctx context.Context) (err error) {
	defer func() {
		c.Close(ctx, err)
	}()
	//未初始化，先读sessionID
	c.sessionKey = getFromHeader(c.conn.GetRequest(), "token")
	if err = c.initClient(ctx); err != nil {
		return
	}
	if err = c.conn.Run(ctx, c); err != nil {
		return
	}
	return
}
func (c *Client) initClient(ctx context.Context) (err error) {
	return
}

func (c *Client) Close(ctx context.Context, err error) {

}

// 从协议头里获得参数
func getFromHeader(req *http.Request, key string) string {
	param := req.Header.Get(key)
	if param == "" {
		param = req.URL.Query().Get(key)
	}
	return param
}

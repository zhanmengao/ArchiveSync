package wsv2

import (
	"context"
	ws "github.com/gorilla/websocket"
	"server/pkg/errors"
	"time"
)

func (c *Conn) write(ctx context.Context, body []byte) (err error) {
	if c.conn == nil {
		err = errors.InternalServer("ws conn is nil", "")
		return
	}
	if err = c.conn.SetWriteDeadline(time.Now().Add(c.readTimeout)); err != nil {
		err = errors.GatewayTimeout("", "").SetBasicErr(err)

		return
	}
	if err = c.conn.WriteMessage(ws.BinaryMessage, body); err != nil {
		err = errors.GatewayTimeout("", "").SetBasicErr(err)
		return
	}
	return
}

// 在ws关闭后退出
func (c *Conn) read(ctx context.Context) (body []byte, err error) {
	if c.conn == nil {
		err = errors.InternalServer("ws conn is nil", "")
		return
	}
	if err = c.conn.SetReadDeadline(time.Now().Add(c.readTimeout)); err != nil {
		err = errors.GatewayTimeout("", "").SetBasicErr(err)
		return
	}
	if _, body, err = c.conn.ReadMessage(); err != nil {
		err = errors.GatewayTimeout("", "").SetBasicErr(err)
		return
	}
	return
}

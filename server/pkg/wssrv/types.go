package wssrv

import (
	"context"
	"net/http"
	"server/pb"
)

type TUrlHandler interface {
	HandleInit(ctx context.Context, request *http.Request, writer http.ResponseWriter) (responseHeader http.Header, err error)
	HandlePacket(ctx context.Context, conn IConnect, rcv []byte)
	HandleClose(ctx context.Context, conn IConnect, err error)
}

type THandlerPacket func(ctx context.Context, conn IConnect, rcv []byte)

func (f THandlerPacket) HandPacket(ctx context.Context, conn IConnect, body []byte) {
	f(ctx, conn, body)
}

type OnlineCallBack func(ctx context.Context, count int)
type ConfigMD5ChangedCallBack func(ctx context.Context, configMD5 string)

type IHandler interface {

	//HandleInit
	//  @Description: 传递sessionID，业务调用FLS接口
	//  @param cli 客户端类封装
	//  @param sessionID SessionID
	//  @return uid 返回UID
	//  @return err 返回错误，出错时连接被关闭
	HandleInit(ctx context.Context, cli *Client, sessionKey string) (uid, deviceToken string, err error)

	//
	// HandleEncode
	//  @Description:加密器
	//  @param ctx
	//  @param cli
	//  @param pkt 原始报文
	//  @return snd 返回编码后的bytes
	//  @return err 出错会断开连接
	HandleEncode(ctx context.Context, cli *Client, pkt *pb.Packet) (snd []byte, err error)

	//
	// HandleDecode
	//  @Description: 解码器
	//  @param ctx
	//  @param rcv 收到原文
	//  @return pkt 返回解出来的packet
	//  @return err 出错会断开连接
	//
	HandleDecode(ctx context.Context, cli *Client, rcv []byte) (pkt *pb.Packet, isSendToSrv bool, err error)

	//HandleClose
	//  @Description: 关闭前的回调，可以发送遗言
	//  @param ctx：上下文
	//  @param cli：客户端类的封装
	//
	HandleClose(ctx context.Context, cli *Client, err error)
}

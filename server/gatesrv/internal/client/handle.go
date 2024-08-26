package client

import (
	"context"
	"github.com/gogo/protobuf/proto"
	"server/pb"
	"server/pkg/wssrv"
)

type Handle struct {
}

func (h Handle) HandleInit(ctx context.Context, cli *wssrv.Client, sessionKey string) (uid, deviceToken string, err error) {
	//TODO implement me
	panic("implement me")
	proto.Marshal()
}

func (h Handle) HandleEncode(ctx context.Context, cli *wssrv.Client, pkt *pb.Packet) (snd []byte, err error) {
	//TODO implement me
	panic("implement me")
}

func (h Handle) HandleDecode(ctx context.Context, cli *wssrv.Client, rcv []byte) (pkt *pb.Packet, isSendToSrv bool, err error) {
	//TODO implement me
	panic("implement me")
}

func (h Handle) HandleClose(ctx context.Context, cli *wssrv.Client, err error) {
	//TODO implement me
	panic("implement me")
}

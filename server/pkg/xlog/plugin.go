package xlog

import (
	"context"
	"server/pkg/util"
)

type TTraceLogger struct {
}

func (g *TTraceLogger) Write(p []byte) (n int, err error) {
	Trace(context.Background(), util.BtsToString(p))
	n = len(p)
	return
}

type TInfoLogger struct {
}

func (g *TInfoLogger) Write(p []byte) (n int, err error) {
	Info(context.Background(), util.BtsToString(p))
	n = len(p)
	return
}

type TErrorLogger struct {
}

func (g *TErrorLogger) Write(p []byte) (n int, err error) {
	Error(context.Background(), util.BtsToString(p))
	n = len(p)
	return
}

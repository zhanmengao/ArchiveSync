package xlog

import (
	"runtime"
	"server/pkg/xlog/internal/f9log"
	"server/pkg/xlog/internal/zzap"
	"server/pkg/xlog/logtyp"
	"strings"
)

func init() {
	goRoot = runtime.GOROOT()
	goRoot = strings.ReplaceAll(goRoot, "\\", "/")
}

func UseF9Log(baseDir, app, name string, lv string) (err error) {
	var l *f9log.Logger
	if l, err = f9log.InitOssLogger(baseDir, app, name, gUsePid); err != nil {
		return
	}
	SetLogger(l)
	gLogLevel = logtyp.ParseLevel(lv)
	gAppName = app
	return
}

func UseZapLog(lv string, dev bool) (err error) {
	zl, err := zzap.DefaultZapConfig(dev)
	if err != nil {
		return
	}
	l := zzap.NewZapLogger(zl)
	SetLogger(l)
	gLogLevel = logtyp.ParseLevel(lv)
	return
}

func SetGlobalSkip(skip int) {
	gSkip = skip
}

func SetGlobalMsgKey(msgKey string) {
	gMsgKey = msgKey
}

func UseJsonFormat() {
	useJsonFormat = true
}

func UseStringFormat() {
	useJsonFormat = false
}

func GetLogLevel() logtyp.Level {
	return gLogLevel
}

func SetLogLevel(lv logtyp.Level) {
	gLogLevel = lv
}

func UsePid(use bool) {
	gUsePid = use
	gLogger.UsePid(use)
}

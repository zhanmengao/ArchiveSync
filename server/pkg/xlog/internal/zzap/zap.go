package zzap

import (
	"context"
	"fmt"
	"go.uber.org/zap/zapcore"
	"server/pkg/xlog/logtyp"

	"go.uber.org/zap"
)

type Logger struct {
	log *zap.Logger
}

func DefaultZapConfig(dev bool) (l *zap.Logger, err error) {
	var zcfg zap.Config
	if dev {
		zcfg = zap.NewDevelopmentConfig()
	} else {
		zcfg = zap.NewProductionConfig()
	}
	zcfg.EncoderConfig.MessageKey = zapcore.OmitKey
	zcfg.EncoderConfig.EncodeTime = zapcore.RFC3339TimeEncoder
	//zcfg.DisableStacktrace = true
	l, err = zcfg.Build(zap.AddCaller(), zap.AddCallerSkip(3))
	return
}

func NewZapLogger(zlog *zap.Logger) *Logger {
	return &Logger{zlog}
}

func (l *Logger) Log(ctx context.Context, info *logtyp.LogInfo) error {
	if len(info.KvList) == 0 || len(info.KvList)%2 != 0 {
		l.log.Warn(fmt.Sprint("Keyvalues must appear in pairs: ", info.KvList))
		return nil
	}

	var data []zap.Field
	for i := 0; i < len(info.KvList); i += 2 {
		data = append(data, zap.Any(fmt.Sprint(info.KvList[i]), info.KvList[i+1]))
	}

	switch info.Lv {
	case logtyp.DEBUG:
		l.log.Debug("Debug => :", data...)
	case logtyp.TRACE:
		l.log.Debug("Trace => : ", data...)
	case logtyp.INFO:
		l.log.Info("Info => :", data...)
	case logtyp.WARN:
		l.log.Warn("Warn => :", data...)
	case logtyp.ERROR:
		l.log.Error("Error => :", data...)
	case logtyp.FATAL:
		l.log.Fatal("Fatal => :", data...)
	}
	return nil
}

func (l *Logger) Sync() error {
	return l.log.Sync()
}

func (l *Logger) UsePid(use bool) {
}

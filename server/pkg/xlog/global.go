package xlog

import (
	"context"
	"server/pkg/xlog/logtyp"
)

// Debug x_logs a message at debug level.
func Debug(ctx context.Context, a ...interface{}) {
	Log(ctx, logtyp.DEBUG, gSkip+1, gMsgKey, a...)
}

// Debugf x_logs a message at debug level.
func Debugf(ctx context.Context, format string, a ...interface{}) {
	Logf(ctx, logtyp.DEBUG, gSkip+1, gMsgKey, format, a...)
}

// Debugw x_logs a message at debug level.
func Debugw(ctx context.Context, keyvals ...interface{}) {
	Logw(ctx, logtyp.DEBUG, gSkip+1, keyvals...)
}

// Trace Debug x_logs a message at debug level.
func Trace(ctx context.Context, a ...interface{}) {
	Log(ctx, logtyp.TRACE, gSkip+1, gMsgKey, a...)
}

// Tracef x_logs a message at debug level.
func Tracef(ctx context.Context, format string, a ...interface{}) {
	Logf(ctx, logtyp.TRACE, gSkip+1, gMsgKey, format, a...)
}

// Tracew x_logs a message at debug level.
func Tracew(ctx context.Context, keyvals ...interface{}) {
	Logw(ctx, logtyp.TRACE, gSkip+1, keyvals...)
}

// Info x_logs a message at info level.
func Info(ctx context.Context, a ...interface{}) {
	Log(ctx, logtyp.INFO, gSkip+1, gMsgKey, a...)
}

// Infof x_logs a message at info level.
func Infof(ctx context.Context, format string, a ...interface{}) {
	Logf(ctx, logtyp.INFO, gSkip+1, gMsgKey, format, a...)
}

// Infow x_logs a message at info level.
func Infow(ctx context.Context, keyvals ...interface{}) {
	Logw(ctx, logtyp.INFO, gSkip+1, keyvals...)
}

// Warn x_logs a message at warn level.
func Warn(ctx context.Context, a ...interface{}) {
	Log(ctx, logtyp.WARN, gSkip+1, gMsgKey, a...)
}

// Warnf x_logs a message at warnf level.
func Warnf(ctx context.Context, format string, a ...interface{}) {
	Logf(ctx, logtyp.WARN, gSkip+1, gMsgKey, format, a...)
}

// Warnw x_logs a message at warnf level.
func Warnw(ctx context.Context, keyvals ...interface{}) {
	Logw(ctx, logtyp.WARN, gSkip+1, keyvals...)
}

// Error x_logs a message at error level.
func Error(ctx context.Context, a ...interface{}) {
	Log(ctx, logtyp.ERROR, gSkip+1, gMsgKey, a...)
}

// Errorf x_logs a message at error level.
func Errorf(ctx context.Context, format string, a ...interface{}) {
	Logf(ctx, logtyp.ERROR, gSkip+1, gMsgKey, format, a...)
}

// Errorw x_logs a message at error level.
func Errorw(ctx context.Context, keyvals ...interface{}) {
	Logw(ctx, logtyp.ERROR, gSkip+1, keyvals...)
}

// Fatal x_logs a message at fatal level.
func Fatal(ctx context.Context, a ...interface{}) {
	Log(ctx, logtyp.FATAL, gSkip+1, gMsgKey, a...)
}

// Fatalf x_logs a message at fatal level.
func Fatalf(ctx context.Context, format string, a ...interface{}) {
	Logf(ctx, logtyp.FATAL, gSkip+1, gMsgKey, format, a...)
}

// Fatalw x_logs a message at fatal level.
func Fatalw(ctx context.Context, keyvals ...interface{}) {
	Logw(ctx, logtyp.FATAL, gSkip+1, keyvals...)
}

func TraceFunc(cb func()) {
	if gLogLevel == logtyp.TRACE {
		cb()
	}
}

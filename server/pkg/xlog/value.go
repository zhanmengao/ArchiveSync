package xlog

import (
	golog "log"
	"server/pkg/xlog/internal/stdlog"
	"server/pkg/xlog/logtyp"
)

const (
	DefaultMessageKey = "msg"
)

var (
	gLogLevel logtyp.Level
	// DefaultLogger default std log.
	tagCallList   []TTagCall
	whiteListCall []TWhiteListCall
	gMsgKey                     = DefaultMessageKey
	gLogger       logtyp.Logger = stdlog.NewStdLogger(golog.Writer())
	gSkip         int
	gAppName      string
	useJsonFormat bool
	goRoot        string
	gUsePid       bool = true
)

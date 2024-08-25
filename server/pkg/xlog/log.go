package xlog

import (
	"context"
	"encoding/json"
	"fmt"
	"runtime/debug"
	"server/pkg/util"
	"server/pkg/xlog/internal/logutil"
	"server/pkg/xlog/logtyp"
	"strings"
	"time"
)

// SetLogger should be called before any other log call.
// And it is NOT THREAD SAFE.
func SetLogger(l logtyp.Logger) {
	gLogger = l
}

// GetLogger returns global logger appliance as logger in current process.
func GetLogger() logtyp.Logger {
	return gLogger
}

// Log Print log by level and keyvals.
func Log(ctx context.Context, level logtyp.Level, skip int, msgKey string, a ...interface{}) {
	if !getIsLog(ctx, level) {
		return
	}
	formatKeyvals(a...)
	log(ctx, level, skip+1, msgKey, fmt.Sprint(a...))
}

func log(ctx context.Context, level logtyp.Level, skip int, keyvals ...interface{}) {
	tl := getTagList(ctx, level)
	kvList := make([]interface{}, 0, len(tl)+len(keyvals))
	local := logutil.LocFormat(gAppName, skip+2)
	for _, tag := range tl {
		kvList = append(kvList, tag)
	}
	st := strings.Split(local, "\t")
	kvList = append(kvList, keyvals...)

	stack := ""
	filee := ""
	funcc := ""
	if len(st) >= 1 {
		filee = st[0]
	}
	if len(st) >= 2 {
		funcc = st[1]
	}
	if level == logtyp.FATAL {
		stack = util.BtsToString(debug.Stack())
		stack = strings.ReplaceAll(stack, "\t", "")
		sl := strings.Split(stack, "\n")
		maxLine := 22
		if len(sl) < 22 {
			maxLine = len(sl)
		}
		minLine := 9
		if len(sl) < 9 {
			minLine = len(sl)
		}
		for i, s := range sl {
			//跳过开头的debug.Stack
			if i > minLine && strings.Contains(s, goRoot) {
				maxLine = i
				break
			}
			if idx := strings.Index(s, "+"); idx > -1 {
				sl[i] = s[0:idx]
			} else if idx = strings.Index(s, "("); idx > -1 {
				sl[i] = s[0:idx]
			}
		}
		if maxLine > minLine {
			stack = strings.Join(sl[minLine:maxLine], " ")
		}
	}
	gLogger.Log(ctx, &logtyp.LogInfo{
		Lv:     level,
		Skip:   skip + 2,
		Stack:  stack,
		File:   filee,
		Func:   funcc,
		Time:   time.Now().Format("[2006-01-02 15:04:05.000 -0700]"),
		KvList: kvList,
	})
}

// Logf Print log by level and keyvals.
func Logf(ctx context.Context, level logtyp.Level, skip int, msgKey string, format string, a ...interface{}) {
	if !getIsLog(ctx, level) {
		return
	}
	logf(ctx, level, skip+1, msgKey, format, a...)
}
func logf(ctx context.Context, level logtyp.Level, skip int, msgKey string, format string, a ...interface{}) {
	formatKeyvals(a...)
	log(ctx, level, skip+1, msgKey, fmt.Sprintf(format, a...))
}

func Logw(ctx context.Context, level logtyp.Level, skip int, keyvals ...interface{}) {
	if !getIsLog(ctx, level) {
		return
	}
	logw(ctx, level, skip+1, keyvals...)
}

func logw(ctx context.Context, level logtyp.Level, skip int, keyvals ...interface{}) {
	formatKeyvals(keyvals...)
	log(ctx, level, skip+1, keyvals...)
}

func formatKeyvals(keyvals ...interface{}) {
	for i, p := range keyvals {
		if err, ok := p.(error); ok {
			keyvals[i] = err.Error()
		} else if pm, ok := p.(fmt.Stringer); ok {
			if useJsonFormat {
				if bt, err := json.Marshal(pm); err == nil {
					keyvals[i] = util.BtsToString(bt)
				}
			} else {
				keyvals[i] = pm.String()
			}
		}
	}
}

func getIsLog(ctx context.Context, level logtyp.Level) bool {
	isLog := false
	if level >= gLogLevel {
		isLog = true
		return true
	}
	for _, f := range whiteListCall {
		isLog = f(ctx, level)
		if isLog {
			break
		}
	}
	return isLog
}

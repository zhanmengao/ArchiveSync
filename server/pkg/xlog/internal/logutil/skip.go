package logutil

import (
	"fmt"
	"path"
	"runtime"
	"strings"
)

// LocFormat returns function name, file name and line number
func LocFormat(procName string, skip int) (stack string) {
	pc, file, line, _ := runtime.Caller(skip)
	funcname := runtime.FuncForPC(pc).Name()
	index := strings.LastIndex(funcname, "/")

	stack = fmt.Sprintf("%s-%s:%d\t%s", procName, path.Base(file), line, funcname[index+1:])
	return
}

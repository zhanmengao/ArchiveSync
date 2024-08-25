package f9log

import (
	"bytes"
	"os"
	"path"
	"sync"
)

var (
	ossLogger *Logger
	// ErrLogger log for error message
	//ErrLogger *ErrorLogger

	consoleLogger *Logger

	procName string
)

type modString string

func init() {
	consoleLogger = &Logger{
		wr: &Writer{
			app: "",
			dir: "",
			fileOp: &fileOp{
				fn: "",
				fp: os.Stdout,
			},
			chExit:  nil,
			RWMutex: sync.RWMutex{},
		},
		mapPool: &sync.Pool{New: func() interface{} {
			m := newTagMap()
			return m
		}},
		bufPool: &sync.Pool{New: func() interface{} {
			buf := make([]byte, 0, 1024)
			bb := bytes.NewBuffer(buf)
			return bb
		}},
		fmtr: NewTEXTFormatter(),
	}
	ossLogger = consoleLogger

}

// InitOssLogger init log
func InitOssLogger(baseDir, app, name string, usePid bool) (log *Logger, err error) {
	dir := path.Join(baseDir, app)
	ossLogger, err = New(dir, app, name, usePid)
	procName = app
	if err != nil {
		return
	}

	//ErrLogger = &ErrorLogger{w: ossLogger}
	log = ossLogger
	return
}

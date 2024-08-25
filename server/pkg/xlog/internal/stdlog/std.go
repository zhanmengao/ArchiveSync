package stdlog

import (
	"bytes"
	"context"
	"fmt"
	"io"
	"log"
	"server/pkg/xlog/logtyp"
	"sync"
	"time"
)

type stdLogger struct {
	log  *log.Logger
	pool *sync.Pool
}

// NewStdLogger new a logger with writer.
func NewStdLogger(w io.Writer) *stdLogger {
	return &stdLogger{
		log: log.New(w, "", 0),
		pool: &sync.Pool{
			New: func() interface{} {
				return new(bytes.Buffer)
			},
		},
	}
}

// Log print the kv pairs log.
func (l *stdLogger) Log(ctx context.Context, info *logtyp.LogInfo) error {
	if len(info.KvList) == 0 {
		return nil
	}
	if (len(info.KvList) & 1) == 1 {
		info.KvList = append(info.KvList, logtyp.DefaultValue)
	}
	buf := l.pool.Get().(*bytes.Buffer)
	buf.Reset()
	buf.WriteString(time.Now().Format("[2006-01-02 15:04:05.000 -0700]"))
	buf.WriteString("\t")
	buf.WriteString(info.Lv.String())
	buf.WriteString("\t")

	for i := 0; i < len(info.KvList); i += 2 {
		_, _ = fmt.Fprintf(buf, " %s=%v", info.KvList[i], info.KvList[i+1])
	}
	_ = l.log.Output(4+info.Skip, buf.String()) //nolint:gomnd
	buf.Reset()
	l.pool.Put(buf)
	return nil
}

func (l *stdLogger) UsePid(use bool) {
}

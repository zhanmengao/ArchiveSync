package f9log

import (
	"bytes"
	"server/pkg/xlog/logtyp"
	"sync"
)

type Logger struct {
	wr      *Writer
	mapPool *sync.Pool
	bufPool *sync.Pool
	fmtr    *TEXTFormatter
	skip    int
}

//const maxLogSize = 4096

func New(dir, app, name string, usePid bool) (l *Logger, err error) {
	wr, err := NewWriter(app, dir, name, usePid)
	if err != nil {
		return
	}
	bufPool := &sync.Pool{New: func() interface{} {
		buf := make([]byte, 0, 1024)
		bb := bytes.NewBuffer(buf)
		return bb
	}}
	mapPool := &sync.Pool{New: func() interface{} {
		m := newTagMap()
		return m
	}}
	l = &Logger{
		wr:      wr,
		mapPool: mapPool,
		bufPool: bufPool,
		fmtr:    NewTEXTFormatter(),
	}
	return
}

// 释放输出资源, 如: 文件描述符
func (l *Logger) Close() (err error) {
	l.wr.Close()
	return
}

func (l *Logger) SetLogWithFunc(b bool) {
	l.fmtr.setLogWithFunc(b)
}

//func (l *Logger) SetLogHook(f func(string) bool) {
//	l.logHook = f
//}

func (l *Logger) output(info *logtyp.LogInfo) {
	buf := l.bufPool.Get()
	defer l.bufPool.Put(buf)
	bb := buf.(*bytes.Buffer)
	bb.Reset()

	////map
	m := l.mapPool.Get().(tagMap)
	defer l.mapPool.Put(m)
	m.Reset()
	l.fmtr.FormatMap(m, info)

	l.fmtr.FormatEncoder(bb, info, m)
	//_ = l.fmtr.FormatEncoder(bb, info)

	l.wr.Write(bb.Bytes())
}

func (l *Logger) UsePid(use bool) {
	l.wr.usePid = use
}

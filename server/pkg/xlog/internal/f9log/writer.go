package f9log

import (
	"fmt"
	"os"
	"path"
	"path/filepath"
	"runtime"
	"server/pkg/errors"
	"strings"
	"sync"
	"time"
)

const DefaultLogFileName = "xlog"

type fileOp struct {
	fn string
	fp *os.File
}
type Writer struct {
	app    string
	dir    string
	name   string
	fileOp *fileOp

	chExit chan bool
	sync.RWMutex
	pid    int
	usePid bool
}

func NewWriter(app, dir, name string, usePid bool) (wr *Writer, err error) {
	st, err := os.Stat(dir)
	if err != nil {
		if err = os.MkdirAll(dir, 0755); err != nil {
			return
		}
	} else if !st.IsDir() {
		err = errors.New(99, "Err Server Internal Unknown", "Err Server Internal Unknown").Format("log dir %s is not a dir", dir)
		return
	}

	if name == "" {
		name = DefaultLogFileName
	}

	wr = &Writer{
		app: app,
		dir: dir,
		//fileOp:  *fileOp,
		chExit: make(chan bool),
		name:   name,
		pid:    os.Getpid(),
		usePid: usePid,
	}

	fn := wr.getFileName(name)

	fp, err := checkAndOpen(fn)
	if err != nil {
		return nil, err
	}
	wr.fileOp = &fileOp{
		fn: fn,
		fp: fp,
	}

	go wr.checker()
	return
}

func (f *Writer) Write(data []byte) (n int, err error) {
	//new file open
	fp := f.getLogFP()
	if fp != nil {
		n, err = fp.Write(data)
	}
	return
}

func (f *Writer) getLogFP() *os.File {
	f.RLock()
	defer f.RUnlock()
	return f.fileOp.fp
}

func (f *Writer) Close() {
	f.Lock()
	defer f.Unlock()

	f.fileOp.fp.Close()

	f.chExit <- true
}

func (f *Writer) checker() {
	tk := time.NewTicker(200 * time.Millisecond)
	for {
		select {
		case <-tk.C:
			f.doCheck()
		case <-f.chExit:
			return
		}
	}
}

func (f *Writer) getKeyByMod(mod string) string {
	return fmt.Sprintf("%s_error_%s", f.app, mod)
}

func (f *Writer) getFileName(mod string) string {
	t := time.Now()
	var d string
	key := f.getKeyByMod(mod)
	if f.usePid {
		d = path.Clean(fmt.Sprintf("%s/%d%02d%02d/%s_%02d_%d.log", f.dir, t.Year(), t.Month(), t.Day(), key, t.Hour(), f.pid))
	} else {
		d = path.Clean(fmt.Sprintf("%s/%d%02d%02d/%s_%02d.log", f.dir, t.Year(), t.Month(), t.Day(), key, t.Hour()))
	}
	if runtime.GOOS == `windows` {
		d = strings.ReplaceAll(d, "/", "\\")
	}
	return d
}

func (f *Writer) doCheck() {
	var (
		fn       string
		fp       *os.File
		st1, st2 os.FileInfo
		err      error
	)
	fn = f.getFileName(f.name)
	st1, err = os.Stat(fn)
	st2 = f.GetFileStat()
	if fn != f.GetFileName() || //文件名不同，代表文件发生了切换
		err != nil || //新的文件无法不存在，代表被删除
		!os.SameFile(st1, st2) { //文件不同，代表被删除
		if fp, err = checkAndOpen(fn); err != nil {
			return
		}
		tmpfp := f.GetPFile()
		f.SetFp(&fileOp{
			fn: fn,
			fp: fp,
		})
		time.AfterFunc(2*time.Second, func() {
			tmpfp.Close()
		})
	}
}

func (f *Writer) SetFp(fop *fileOp) {
	f.Lock()
	defer f.Unlock()
	f.fileOp = fop
}

func (f *Writer) GetFileStat() os.FileInfo {
	f.RLock()
	defer f.RUnlock()
	st, _ := f.fileOp.fp.Stat()
	return st
}

func (f *Writer) GetFileName() string {
	f.RLock()
	defer f.RUnlock()
	return f.fileOp.fn
}

func (f *Writer) GetPFile() *os.File {
	f.RLock()
	defer f.RUnlock()
	return f.fileOp.fp
}

func checkAndOpen(fn string) (fp *os.File, err error) {
	dir := filepath.Dir(fn)
	if _, err = os.Stat(dir); err != nil {
		if err = os.MkdirAll(dir, 0755); err != nil {
			return
		}
	}
	fp, err = os.OpenFile(fn, os.O_CREATE|os.O_APPEND|os.O_RDWR, 0644)
	return
}

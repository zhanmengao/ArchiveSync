package f9log

import (
	"bytes"
	"encoding/json"
	"fmt"
	"os"
	"server/pkg/xlog/logtyp"
	"strconv"
)

type TEXTFormatter struct {
	pid         []byte
	pids        string
	logWithFunc bool
}

func NewTEXTFormatter() *TEXTFormatter {
	pid := os.Getpid()
	ret := &TEXTFormatter{
		pid:         []byte(strconv.Itoa(pid)),
		pids:        strconv.Itoa(pid),
		logWithFunc: true,
	}
	return ret
}

func (t *TEXTFormatter) setLogWithFunc(b bool) {
	t.logWithFunc = b
}

func (t *TEXTFormatter) FormatMap(m tagMap, entry *logtyp.LogInfo) (err error) {
	for i := 0; i < len(entry.KvList); i += 2 {
		k := fmt.Sprint(entry.KvList[i])
		if i+1 < len(entry.KvList) {
			m[k] = fmt.Sprint(entry.KvList[i+1])
		} else {
			m[k] = logtyp.DefaultValue
		}
	}
	return
}

func (t *TEXTFormatter) FormatJson(buf *bytes.Buffer, entry *logtyp.LogInfo, m tagMap) (err error) {
	buf.Reset()
	buf.WriteString(entry.Time)
	buf.WriteString("\t")
	buf.WriteString(entry.Lv.String())
	buf.WriteString("\t")
	buf.Write(t.pid)
	buf.WriteString("\t")
	buf.WriteString(entry.File)
	buf.WriteString("\t")

	m["func"] = entry.Func
	data, err := json.Marshal(m)
	if err != nil {
		return
	} else {
		buf.Write(data)
	}
	if entry.Stack != "" {
		buf.WriteString(entry.Stack)
	}
	buf.WriteString("\n")

	return
}

func (t *TEXTFormatter) FormatEncoder(buf *bytes.Buffer, entry *logtyp.LogInfo, m tagMap) (err error) {
	buf.Reset()
	buf.WriteString(entry.Time)
	buf.WriteString("\t")
	buf.WriteString(entry.Lv.String())
	buf.WriteString("\t")
	buf.Write(t.pid)
	buf.WriteString("\t")
	buf.WriteString(entry.File)
	buf.WriteString("\t")
	if m != nil {
		m["func"] = entry.Func
	} else {
		entry.KvList = append(entry.KvList, "func", entry.Func)
	}

	enc := json.NewEncoder(buf)
	enc.SetEscapeHTML(false)
	err = enc.Encode(m)
	if err != nil {
		return
	}
	buf.WriteString(buf.String())

	if entry.Stack != "" {
		buf.WriteString(entry.Stack)
	}
	buf.WriteString("\n")

	return
}

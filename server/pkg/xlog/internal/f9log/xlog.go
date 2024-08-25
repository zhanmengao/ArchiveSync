package f9log

import (
	"context"
	"fmt"
	"log"
	"server/pkg/xlog/logtyp"
)

func (l *Logger) Log(ctx context.Context, info *logtyp.LogInfo) error {
	if len(info.KvList) == 0 || len(info.KvList)%2 != 0 {
		log.Println(fmt.Sprint("Keyvalues must appear in pairs: ", info.KvList))
		return nil
	}
	l.output(info)
	return nil
}

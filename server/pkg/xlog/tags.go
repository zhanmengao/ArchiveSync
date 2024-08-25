package xlog

import (
	"context"
	"server/pkg/xlog/logtyp"
)

// UseLogTag
//
//	@Description: 向日志库注册tag函数，用于在每次打印日志时根据ctx追加tag
//	@param cb 回调函数，返回[]string
func UseLogTag(cb TTagCall) {
	if cb != nil {
		tagCallList = append(tagCallList, cb)
	}
}

func getTagList(ctx context.Context, lv logtyp.Level) (tl []string) {
	if len(tagCallList) <= 0 {
		return
	}
	tl = make([]string, 0, 2)
	for _, f := range tagCallList {
		t := f(ctx, lv)
		if len(t) > 0 {
			tl = append(tl, t...)
			if len(t)%2 != 0 {
				tl = append(tl, logtyp.DefaultValue)
			}
		}
	}
	return
}

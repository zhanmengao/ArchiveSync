package xlog

func UseWhiteList(cb TWhiteListCall) {
	if cb != nil {
		whiteListCall = append(whiteListCall, cb)
	}
}

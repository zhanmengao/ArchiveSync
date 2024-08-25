package prom

import "server/pkg/errors"

var (
	errBadParam = errors.NewError(1001, "bad param")
	errNetwork  = errors.NewError(1002, "network error")
)

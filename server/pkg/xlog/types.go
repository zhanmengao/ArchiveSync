package xlog

import (
	"context"
	"server/pkg/xlog/logtyp"
)

type TTagCall func(ctx context.Context, logLevel logtyp.Level) []string

type TWhiteListCall func(ctx context.Context, logLevel logtyp.Level) bool

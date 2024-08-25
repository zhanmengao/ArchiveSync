package logtyp

import "context"

// Logger is a exlog interface.
type Logger interface {
	Log(ctx context.Context, info *LogInfo) error
	UsePid(use bool)
}

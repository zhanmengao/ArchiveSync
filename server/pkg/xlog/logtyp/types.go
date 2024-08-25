package logtyp

import "strings"

type LogInfo struct {
	Lv     Level
	Skip   int
	File   string
	Func   string
	Stack  string
	KvList []interface{}
	Time   string
}

// Level is a exlog level.
type Level int8

// LevelKey is exlog level key.
const LevelKey = "level"

const (
	TRACE Level = iota - 2
	DEBUG
	INFO
	NOTICE
	WARN
	ERROR
	FATAL
	OFF
)

func (l Level) String() string {
	switch l {
	case TRACE:
		return "TRACE"
	case DEBUG:
		return "DEBUG"
	case INFO:
		return "INFO"
	case NOTICE:
		return "NOTICE"
	case WARN:
		return "WARN"
	case ERROR:
		return "ERROR"
	case FATAL:
		return "FATAL"
	case OFF:
		return "OFF"
	default:
		return ""
	}
}

// ParseLevel parses a level string into a exlog Level value.
func ParseLevel(s string) Level {
	switch strings.ToUpper(s) {
	case "TRACE":
		return TRACE
	case "DEBUG":
		return DEBUG
	case "INFO":
		return INFO
	case "NOTICE":
		return NOTICE
	case "WARN":
		return WARN
	case "ERROR":
		return ERROR
	case "FATAL":
		return FATAL
	case "OFF":
		return OFF
	}
	return INFO
}

// ParseString parses a level string into a exlog Level value.
func ParseString(lv Level) string {
	switch lv {
	case TRACE:
		return "TRACE"
	case DEBUG:
		return "DEBUG"
	case INFO:
		return "INFO"
	case NOTICE:
		return "NOTICE"
	case WARN:
		return "WARN"
	case ERROR:
		return "ERROR"
	case FATAL:
		return "FATAL"
	case OFF:
		return "OFF"
	}
	return "INFO"
}

package prom

import (
	"context"
	"fmt"
	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/push"
	"server/pkg/errors"
	"strconv"
	"sync"
	"time"
)

const (
	LabelCMD            = "cmd"
	LabelCallerPlatform = "platform"
	LabelErrorCode      = "code"
	LabelBodyType       = "body_type"
	LabelRpcName        = "rpc_name"
	LabelFRpcCMD        = "frpc_cmd"
)

var once sync.Once
var durations *prometheus.HistogramVec //请求耗时
var reqCount *prometheus.CounterVec    //QPS
var onlineCount *prometheus.GaugeVec   //在线数
var bodySize *prometheus.HistogramVec  //请求Body大小

func InitRPCProm(projectName, serverName string) {
	once.Do(func() {
		durations = prometheus.NewHistogramVec(
			prometheus.HistogramOpts{
				Name:    fmt.Sprintf("%s_request_duration_ms", projectName),
				Help:    "接口耗时",
				Buckets: []float64{1, 400, 1000, 8000},
			},
			[]string{LabelCallerPlatform, LabelCMD, LabelFRpcCMD},
		)
		reqCount = prometheus.NewCounterVec(
			prometheus.CounterOpts{
				Name: fmt.Sprintf("%s_request_total", projectName),
				Help: "服务总请求数",
			},
			[]string{LabelCallerPlatform, LabelCMD, LabelErrorCode, LabelRpcName, LabelFRpcCMD},
		)
		onlineCount = prometheus.NewGaugeVec(
			prometheus.GaugeOpts{
				Name: fmt.Sprintf("%s_online_total", projectName),
				Help: "服务在线人数",
			}, []string{LabelCallerPlatform})
		bodySize = prometheus.NewHistogramVec(
			prometheus.HistogramOpts{
				Name:    fmt.Sprintf("%s_request_body_sz", projectName),
				Help:    "包体大小",
				Buckets: []float64{64, 1024, 10240},
			},
			[]string{LabelCallerPlatform, LabelCMD, LabelBodyType, LabelFRpcCMD},
		)
		prometheus.MustRegister(durations, reqCount, onlineCount, bodySize)
		prom.AddCollector(durations, reqCount, onlineCount, bodySize)
		prom.RegisterPushCall(pushTagCall)
	})
}

// ReportDuration 上报接口延迟时间。fgrpc,fhttp,frpc会自动调用
// platform: 调用方平台
// cmd : 调用的接口
// use : 延迟(ns)
func ReportDuration(platform, cmd string, fRpcCMD int, use time.Duration) {
	if durations == nil {
		return
	}
	ms := float64(use.Milliseconds())
	durations.With(prometheus.Labels{
		LabelCallerPlatform: platform,
		LabelCMD:            cmd,
		LabelFRpcCMD:        strconv.Itoa(fRpcCMD),
	}).Observe(ms)
}

// ReportRequest 统计QPS等。fgrpc,fhttp,frpc会自动调用
// platform 调用方的平台
// cmd 访问的借口或者URL
func ReportRequest(platform string, rpcName, cmd string, fRpcCMD int, err error) {
	if reqCount == nil {
		return
	}
	reqCount.With(prometheus.Labels{
		LabelCallerPlatform: platform,
		LabelCMD:            cmd,
		LabelErrorCode:      strconv.Itoa(errors.Code(err)),
		LabelRpcName:        rpcName,
		LabelFRpcCMD:        strconv.Itoa(fRpcCMD),
	}).Inc()
}

func ReportReqSize(platform string, cmd string, fRpcCMD int, reqSz int) {
	bodySize.With(prometheus.Labels{
		LabelCallerPlatform: platform,
		LabelCMD:            cmd,
		LabelBodyType:       "req",
		LabelFRpcCMD:        strconv.Itoa(fRpcCMD),
	}).Observe(float64(reqSz))
}

func ReportRspSize(platform string, cmd string, fRpcCMD int, rspSize int) {
	bodySize.With(prometheus.Labels{
		LabelCallerPlatform: platform,
		LabelCMD:            cmd,
		LabelBodyType:       "rsp",
		LabelFRpcCMD:        strconv.Itoa(fRpcCMD),
	}).Observe(float64(rspSize))
}

func ReportOnline(platform string, count int) {
	if onlineCount == nil {
		return
	}
	onlineCount.With(prometheus.Labels{
		LabelCallerPlatform: platform,
	}).Set(float64(count))
}

// 回调
func pushTagCall(ctx context.Context, cli *push.Pusher) {
	if route.GetProxy() != nil {
		//加个状态标签
		cli.Grouping("t_status", 1)
	}
}

#include "logmanager.h"
#include<stdio.h>
#include<stdarg.h>

xlog::xlog(QObject *parent)
    : QObject{parent}
{}



void xlog::Info(const char* format,...){
    va_list args;
    va_start(args, 0);
    char buf[1024] = {0};
    sprintf(buf,format,args);
    qDebug(buf);
    va_end(args);
}

void xlog::Debug(const QString& log){
    qDebug(log.toStdString().c_str());
}
void xlog::Info(const QString& log){
    qDebug(log.toStdString().c_str());
}
void xlog::Error(const QString& log){
    qDebug(log.toStdString().c_str());
}

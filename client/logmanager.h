#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QObject>
#include<QString>

#define Debugf(format,args)   xlog::Debug(QString(format).arg(args));
#define Infof(format,args)   xlog::Info(QString(format).arg(args));
#define Errorf(format,args)   xlog::Error(QString(format).arg(args));

class xlog : public QObject
{
    Q_OBJECT
public:
    explicit xlog(QObject *parent = nullptr);
    static void Debug(const QString& log);
    static void Info(const char* format,...);
    static void Info(const QString& log);
    static void Error(const QString& log);
signals:
};

#endif // LOGMANAGER_H

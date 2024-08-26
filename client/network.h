#ifndef NETWORK_H
#define NETWORK_H

#include<stdio.h>
#include<string>
#include<QtWebSockets/QtWebSockets>
#include<QWidget>
#include<QMap>

#include<QMutex>
#include"packet.h"

const QString AppID = "";
const QString AppSecret = "";
const QString GatewayAddr = "ws://127.0.0.1:8084/gate/ws";

class NetworkManager:public QWidget{
public:
    NetworkManager(QWidget* parent);
    static NetworkManager* Ins();
    void ConnectServer(const QString& token);
    void SendPacket(int cmd,Marshal* data);
    void onConnect();
    void onDisConnect();
    void onRecvied(const QByteArray &message);
    void onError(QAbstractSocket::SocketError err);
private:
    static NetworkManager* _ins;
    QWebSocket* gateConn;
    QMutex lock;
    int SeqID;
    int SendID;
    int AckID;
    QMap<int,packet> cmdMap;
};

#endif // NETWORK_H

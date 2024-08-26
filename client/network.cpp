//使用websocket和后台建立连接
#include"network.h"
#include<stdio.h>
#include"logmanager.h"
#include<QLineEdit>
#include<stdlib.h>
#include"struct.pb.h"
#include"packet.h"
#include<QByteArray>

NetworkManager::NetworkManager(QWidget* parent):QWidget(parent),gateConn(nullptr){

    NetworkManager::_ins = this;
}
NetworkManager* NetworkManager::Ins(){
    return _ins;
}


void NetworkManager::ConnectServer(const QString& token){
    //根据Token，调用Login接口连后台
    QString addr = QString("%1?token=%2").arg(GatewayAddr,token);
    lock.lock();
    if(gateConn!=nullptr){
        gateConn->close();
        gateConn = nullptr;
    }
    gateConn = new QWebSocket(addr);
    connect(gateConn,&QWebSocket::connected,this,QOverload<>::of(&NetworkManager::onConnect));
    connect(gateConn,&QWebSocket::disconnected,this,QOverload<>::of(&NetworkManager::onDisConnect));
    connect(gateConn,&QWebSocket::binaryMessageReceived,this,QOverload<const QByteArray&>::of(&NetworkManager::onRecvied));
    connect(gateConn,&QWebSocket::errorOccurred,this,QOverload<QAbstractSocket::SocketError>::of(&NetworkManager::onError));
    lock.unlock();
    gateConn->open(addr);
}
void NetworkManager::SendPacket(int cmd,Marshal* data){
    pb::Packet packet;
    packet.set_cmd(cmd);
    std::string body = data->SerializeAsString();
    packet.set_allocated_body(&body);
    packet.SerializeAsString();
    //发出去
    packet.set_ackid(AckID);
    packet.set_sendid(SendID);
    packet.set_seqid(SeqID);
    gateConn->sendBinaryMessage(QByteArray(packet.SerializePartialAsString().c_str()));
}

void NetworkManager::onConnect(){
    Infof("建立连接 %1",gateConn->origin());
}
void NetworkManager::onDisConnect(){
    Infof("断开连接 %1",gateConn->origin());
}
void NetworkManager::onRecvied(const QByteArray &message){
    Debugf("收到数据 len(%1)",message.length());
    //反序列化
    pb::Packet packet;
    packet.ParseFromArray(message.constData(),message.length());
}
void NetworkManager::onError(QAbstractSocket::SocketError err){

}

NetworkManager* NetworkManager::_ins = nullptr;

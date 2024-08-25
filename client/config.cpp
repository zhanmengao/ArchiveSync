#include "config.h"
#include<QCoreApplication>
#include<QDir>
#include<QFile>
#include<QDataStream>
#include"encode.h"
#include<QJsonObject>
#include<QJsonDocument>
ConfigManager::ConfigManager():encryption(QAESEncryption::AES_128, QAESEncryption::CBC,QAESEncryption::Padding::ZERO) {
    Reload();
}


config ConfigManager::Reload(){
    //配置文件路径
    QFile cfgFile(ConfigFile());
    if(!cfgFile.open(QFile::ReadOnly)){
        //读不到，说明没有配置
    }else{
        //用文本内容先AES解密，再对json进行反序列化
        QDataStream out(&cfgFile);
        QByteArray data;
        out>>data;
        //AES解密
        QByteArray jsonStr = this->encryption.decode(data,AesKey);
        //json反序列化
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr);
        QJsonObject jsonObj = jsonDoc.object();
        cfg.Token = jsonObj["Token"].toString();
    }
    cfgFile.close();
    return cfg;
}

void ConfigManager::SetToken(const QString& token){
    this->cfg.Token = token;
    SaveConfig();
}
void ConfigManager::SaveConfig(){
    QJsonObject obj;
    obj.insert("Token",this->cfg.Token);
    QJsonDocument doc(obj);
    QByteArray jsonStr = doc.toJson(QJsonDocument::Compact);
    //加密
    QByteArray encodeStr = this->encryption.encode(jsonStr,AesKey);
    //写文件
    QFile cfgFile(ConfigFile());
    QDataStream in(&cfgFile);
    in<<encodeStr;
    cfgFile.close();
}

config ConfigManager::GetConfig(){
    return cfg;
}

QString ConfigManager::ConfigFile(){
    QString logPath = QCoreApplication::applicationDirPath()+"config";
    return logPath;
}

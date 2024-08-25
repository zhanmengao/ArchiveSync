#ifndef CONFIG_H
#define CONFIG_H
#include<QString>
#include"encode.h"

struct config{
    QString Token;
};
const QByteArray AesKey = "1234567890123456";
class ConfigManager
{
public:
    ConfigManager();
    config Reload();
    config GetConfig();
    void SetToken(const QString& token);
    void SaveConfig();
    QString ConfigFile();
private:
    config cfg;
    QAESEncryption encryption;
};



#endif // CONFIG_H

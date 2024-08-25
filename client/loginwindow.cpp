#include "loginwindow.h"
#include"network.h"
#include"logmanager.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget{parent}
{
    this->resize(parent->width(),parent->height());
    this->WxLogin();
}


void LoginWindow::WxLogin(){
    //打开时构造
#ifdef QT_DEBUG
    tokenInput = new QLineEdit(this);
    connect(tokenInput,&QLineEdit::returnPressed,this,QOverload<>::of(&LoginWindow::onEnterClick));
#elif _WIN32,_WIN64,__linux__,__unix__
    wxLoginWeb = new WxLoginPage(this);
    QUrl url = QUrl("https://www.baidu.com/");
    wxLoginWeb->load(url);
    wxLoginWeb->addItemUrl(url);
    wxLoginWeb->show();
    return QString("");
#elif __ANDROID__
#endif
}

void LoginWindow::onEnterClick(){
    xlog::Info(QString("点击登录，Token %1").arg(tokenInput->text()));
    NetworkManager::Ins()->ConnectServer(tokenInput->text());
    //关闭UI
    this->hide();
}

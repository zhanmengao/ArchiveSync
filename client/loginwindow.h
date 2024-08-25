#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include"wxlogin.h"
#include<QLineEdit>

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);
    void WxLogin();
    void onEnterClick();
signals:
private:
    WxLoginPage *wxLoginWeb;
    QLineEdit* tokenInput;
};

#endif // LOGINWINDOW_H

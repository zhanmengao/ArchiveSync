#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    //初始化模块
    netManager = new NetworkManager(this);
    cfgManager = new ConfigManager();


    QString token = cfgManager->GetConfig().Token;
    //如果有token，直接登录并调用maintab
    if(!token.isEmpty()){
        netManager->ConnectServer(token);
        mainTab = new MainTab(this);
        mainTab->show();
    }else{
        //否则弹登录window
        loginWindow = new LoginWindow(this);
        loginWindow->show();
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

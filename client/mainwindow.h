#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTabWidget>
#include<QTabBar>
#include<QWidget>
#include<QPushButton>
#include"clipboad.h"
#include"network.h"
#include"config.h"
#include"loginwindow.h"
#include"maintab.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    NetworkManager *netManager;
    ConfigManager *cfgManager;
    LoginWindow *loginWindow;
    MainTab *mainTab;
};
#endif // MAINWINDOW_H

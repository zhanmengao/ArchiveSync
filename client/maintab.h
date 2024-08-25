#ifndef MAINTAB_H
#define MAINTAB_H

#include <QWidget>
#include<QTabWidget>
#include<QTabBar>
#include<QWidget>
#include<QPushButton>
#include"clipboad.h"

class MainTab : public QWidget
{
    Q_OBJECT
public:
    explicit MainTab(QWidget *parent = nullptr);

signals:
private:
    QTabWidget *tab;
    QTabBar *tBar;
    QWidget *clip;
    QWidget *pic;
};

#endif // MAINTAB_H

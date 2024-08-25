#include "maintab.h"

MainTab::MainTab(QWidget *parent): QWidget{parent}
{
    tab = new QTabWidget(this);
    clip = new ClipBoard();
    pic = new QWidget();
    tab->addTab(clip,QIcon("../resources/browser.png"),"剪切板");
    tab->addTab(pic,QIcon("../resources/users.png"),"图片");
    tab->setGeometry(0, 0, parent->width(), parent->height());
    connect(tab,SIGNAL(currentChanged(int)),this,SLOT(currentTab(int)));


    //TODO 图片同步实现。通过websrv上传cos
}

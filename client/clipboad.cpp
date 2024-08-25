#include "clipboad.h"
#include"textitem.h";

ClipBoard::ClipBoard(QWidget *parent): QWidget{parent}{
    //初始化
    textList = new QTabWidget(this);
}



void ClipBoard::SetTextList(const std::vector<pb::TextItem*> tl){
    textList->clear();
    for(int i = 0;i<tl.size();i++){
        this->AddText(tl[i]);
    }

}

void ClipBoard::AddText(pb::TextItem* item){
    textList->addTab(new TextItem(textList),QString(item->text().c_str()));
}

#ifndef CLIPBOAD_H
#define CLIPBOAD_H

#include <QWidget>
#include<QTabWidget>
#include"pb/struct.pb.h"
#include<vector>

class ClipBoard : public QWidget
{
    Q_OBJECT
public:
    explicit ClipBoard(QWidget *parent = nullptr);
    void SetTextList(const std::vector<pb::TextItem*> tl);
    void AddText(pb::TextItem* item);
signals:
private:
    //滑动列表
    QTabWidget* textList;
    QString currentClip;    //缓存当前的剪切板文本，发现不一样时，向服务器同步
};

#endif // CLIPBOAD_H

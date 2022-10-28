#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include "mylistviewitem.h"
#include <QListWidget>
#include <QListView>
#include <QAbstractItemView>

class MyListView:public QListView
{
    Q_OBJECT
public:
    explicit MyListView(QWidget *parent = nullptr);

    void setModel(QAbstractItemModel *model) override;
private:
};

#endif // MYLISTVIEW_H

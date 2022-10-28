#ifndef MYLISTVIEWITEM_H
#define MYLISTVIEWITEM_H

#include <QListWidgetItem>

class MyListViewItem:public QListWidgetItem
{
public:
    explicit MyListViewItem(
            QString itemTitle,
            int pos,
            QListWidget *parent = nullptr);
};

#endif // MYLISTVIEWITEM_H

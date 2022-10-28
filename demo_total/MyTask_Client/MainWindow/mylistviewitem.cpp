#include "mylistviewitem.h"

MyListViewItem::MyListViewItem(QString itemTitle, int pos, QListWidget *parent):
    QListWidgetItem(parent)
{
    setText(itemTitle);
    setSizeHint(QSize(350,50));
}

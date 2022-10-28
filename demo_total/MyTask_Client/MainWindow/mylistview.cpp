#include "mylistview.h"

MyListView::MyListView(QWidget *parent)
{

}

void MyListView::setModel(QAbstractItemModel *model)
{

    QListView::setModel(model);
}

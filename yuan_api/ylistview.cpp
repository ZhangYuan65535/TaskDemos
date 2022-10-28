#include "ylistview.h"
#include <QDebug>

YListView::YListView(QWidget *parent) : QWidget(parent)
{

}

void YListView::setModel(YTabelModel *model,QWidget *widget)
{
    m_model = model;

}



#include <QStandardItemModel>
#include "mainwidget.h"
#include "tempdelegate.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    m_model(new QStandardItemModel()),
    m_view(new QTableView(this)),
    m_settings(new QGSettings("yuan.task.demo5","/yuan/task/demo5/"))
{
    this->setGeometry(0,0,1750,750);
    m_view->setGeometry(this->geometry());

    readInfo();

    for(int i = 0; i < m_list.size(); i+=5){
        QList<QStandardItem*> list;
        for(int j = i; j < i + 5; j++){
            if(j >=m_list.size())
                break;
            QStandardItem *item = new QStandardItem();
            item->setData(QVariant::fromValue(m_list.at(j)));
            list << item;
        }
        qWarning() << list.size();
        m_model->appendRow(list);
    }

    m_view->setModel(m_model);
    m_view->setItemDelegate(new TempDelegate(this));
    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_view->setSelectionMode(QAbstractItemView::NoSelection);
    m_view->horizontalHeader()->setVisible(false);
    m_view->verticalHeader()->setVisible(false);
    m_view->setGeometry(0,0,1750,750);


    for(int i = 0; i < 5; i++){
        m_view->setColumnWidth(i,350);
        m_view->setRowHeight(i,250);
    }
}

void MainWidget::readInfo()
{
    QStringList keyList = m_settings->keys();
    for(auto str : keyList){
        QString val = m_settings->get(str).toString();
        QStringList list = val.split(",");
        ItemData item;
        item.name = list.at(0);
        item.age = list.at(1);
        item.phone = list.at(2);
        item.id = list.at(3);
        item.addr = list.at(4);
        item.temp = list.at(5);
        m_list << item;
    }
}

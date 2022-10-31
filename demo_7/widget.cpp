#include <QStandardItemModel>
#include <QListView>
#include <QDebug>
#include <QProcess>
#include <QPushButton>
#include "widget.h"
#include "itemdata.h"
#include "itemdelegate.h"
#include "addappdialog.h"

// 由于目前还没搞明白 dde-launcher 是从哪获取的应用相关的数据，所以这里先写死，日后再拓展
const QStringList icons = {
    ":/icons/microsoft-edge.png",
    ":/icons/sunlogin_client.png",
    ":/icons/typora.png",
};

const QStringList names = {
    "Edge浏览器",
    "向日葵",
    "Typora",
};

const QStringList paths = {
    "/opt/apps/com.browser.softedge.stable/files/microsoft-edge",
    "/opt/apps/com.oray.sunlogin.client/files/bin/sunloginclient",
    "/opt/apps/io.typora/files/Typora",
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(800,600);

    QPushButton *btn = new QPushButton(this);
    btn->setText("添加新应用");
    btn->move(320,30);
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(deal_addNewApp()));

    load();
}

Widget::~Widget()
{

}

/**
 * @brief Widget::load 加载窗口内的所有控件
 */
void Widget::load()
{
    m_model = new QStandardItemModel();
    for(int i = 0; i < icons.size(); i++){
        QStandardItem *item = new QStandardItem();
        ItemData itemdata;
        itemdata.appName = names.at(i);
        itemdata.iconPath = icons.at(i);
        itemdata.desktopPath = paths.at(i);
        item->setData(QVariant::fromValue(itemdata),Qt::UserRole+1);
        m_model->appendRow(item);
    }
    ItemDelegate *itemdelegate = new ItemDelegate(this);

    QListView *listview = new QListView(this);
    listview->setItemDelegate(itemdelegate);
    listview->setModel(m_model);
    listview->setFixedSize(300,this->height());
    listview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(listview,SIGNAL(clicked(QModelIndex)),this,SLOT(deal_clicked(QModelIndex)));
}

/**
 * @brief Widget::deal_clicked 打开应用
 * 当点击 app item 时，该槽函数负责打开新应用
 * @param index 被点击的 item 的索引
 */
void Widget::deal_clicked(QModelIndex index)
{
    QVariant var = index.data(Qt::UserRole + 1);
    ItemData itemdata = var.value<ItemData>();
    qWarning() << itemdata.appName ;
    qWarning() << itemdata.iconPath;
    qWarning() << itemdata.desktopPath;

    QProcess *process = new QProcess(this);
    process->startDetached(itemdata.desktopPath);
}

/**
 * @brief Widget::deal_addNewApp 槽函数，添加新应用
 */
void Widget::deal_addNewApp()
{
    AddAppDialog dialog(this);
    dialog.exec();
    QList<QString> list =  dialog.getInfo();

    QStandardItem *item = new QStandardItem();
    ItemData itemdata;
    itemdata.appName = list.at(0);
    itemdata.iconPath = list.at(1);
    itemdata.desktopPath = list.at(2);
    item->setData(QVariant::fromValue(itemdata),Qt::UserRole+1);
    m_model->appendRow(item);
}

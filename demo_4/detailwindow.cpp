#include "detailwindow.h"
#include "productwidget.h"

const int c_row = 3;
const int c_col = 4;
const QList<QString> icons{
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
    ":/Icons/milk_tea.jpg",
};
const QList<QString> names{
    "绿茶","红茶","柠檬茶",
    "绿茶","红茶","柠檬茶",
    "绿茶","红茶","柠檬茶",
    "绿茶","红茶","柠檬茶",
};
const QList<double> prices{
    8,12,6,17,
    7,10,14,6,
    8,12,6,17,
};

DetailWindow::DetailWindow(QWidget *parent) : QWidget(parent)
{
    initData();
    initGUI();
}

void DetailWindow::initData()
{
    m_icons.append(icons);
    m_names.append(names);
    m_prices.append(prices);
}

void DetailWindow::initGUI()
{
    this->setFixedSize(600,600);

    m_model = new QStandardItemModel(c_row,c_col,this);
    m_tableView = new QTableView(this);

    m_tableView->setModel(m_model);
    for(int i = 0; i < 4; i++){
        m_tableView->setColumnWidth(i,150);
    }
    for(int i = 0; i < 3; i++){
        m_tableView->setRowHeight(i,200);
    }
    m_tableView->resize(this->size());

    for(int i = 0; i < icons.size(); i++){
        ProductWidget *product = new ProductWidget(m_icons.at(i),m_names.at(i),m_prices.at(i),this);
        int row = i / 4;
        int col = i % 4;
        QModelIndex index = m_model->index(row,col);
        m_tableView->setIndexWidget(index,product);
    }
    m_tableView->horizontalHeader()->setVisible(false);
    m_tableView->verticalHeader()->setVisible(false);
}

#include "mainwindow.h"
#include "mylistview.h"
#include "incwidget.h"
#include "primewidget.h"
#include "factorialwidget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>
#include <QStandardItemModel>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    leftWidget(nullptr),
    layout(nullptr),
    rightWidget(nullptr),
    model(nullptr),
    highLightItem(nullptr),
    m_circleWidget(nullptr)
{
    this->setWindowTitle("初级运算器");
    this->setGeometry(600,290,600,500);
    normalBg = new QBrush(QColor(0,0,0,0));
    highLightBg= new QBrush(QColor(178,178,178,178));
    loadModel();
    createGUI();
    setMouseTracking(true);

    interfaceAdapter = new DBusInterfaceAdapter(
                "yuan.task.func",
                "/yuan/task/func",
                "yuan.task.func");

    connect(leftWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(changeLeftWidget(QModelIndex)));
    connect(leftWidget,SIGNAL(entered(QModelIndex)),this,SLOT(EnterLeftItem(QModelIndex)));
    connect(this,SIGNAL(outOfLeftItem()),this,SLOT(OuterLeftItem()));
}

void MainWindow::loadModel()
{
    model = new QStandardItemModel;
    QStandardItem *iteminc = new QStandardItem;
    QStandardItem *itemfactorial = new QStandardItem;
    QStandardItem *itemprime = new QStandardItem;

    iteminc->setData(QVariant::fromValue(QString("加法")),Qt::DisplayRole);
    iteminc->setSizeHint(QSize(200,50));
    iteminc->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    iteminc->setBackground(*normalBg);
    model->setItem(0,iteminc);

    itemfactorial->setData(QVariant::fromValue(QString("阶乘")),Qt::DisplayRole);
    itemfactorial->setSizeHint(QSize(200,50));
    itemfactorial->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    itemfactorial->setBackground(*normalBg);
    model->setItem(1,itemfactorial);

    itemprime->setData(QVariant::fromValue(QString("求质数")),Qt::DisplayRole);
    itemprime->setSizeHint(QSize(200,50));
    itemprime->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    itemprime->setBackground(*normalBg);
    model->setItem(2,itemprime);

    highLightItem = iteminc;
    iteminc->setBackground(*highLightBg);
}

void MainWindow::createGUI()
{
    layout = new QGridLayout(this);
    leftWidget = new QListView(this);
    leftWidget->setModel(model);
    leftWidget->setMaximumWidth(200);
    leftWidget->setMaximumWidth(200);
    leftWidget->setSelectionRectVisible(true);
    leftWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    leftWidget->setMouseTracking(true);

    rightWidget = new QStackedWidget(this);
    rightWidget->setMaximumWidth(this->geometry().width()-200);
    rightWidget->setMaximumWidth(this->geometry().width()-200);

    btn_quit = new MyButton(":/images/quit.svg",this);

    layout->addWidget(leftWidget,0,0,2,1,Qt::AlignLeft);
    layout->addWidget(rightWidget,0,1,1,1,Qt::AlignVCenter);
    layout->addWidget(btn_quit,1,1,1,1,Qt::AlignRight);

    m_circleWidget = new CircleWidget;
    m_circleWidget->setGeometry(this->geometry().width()/2-50,this->geometry().height()/2-50,100,100);
    m_circleWidget->setParent(this);
    m_circleWidget->setNoLoading();

    IncWidget *incWidget = new IncWidget;
    rightWidget->addWidget(incWidget);
    connect(incWidget->btn_calculate,SIGNAL(clicked(bool)),incWidget,SLOT(calculate()));
    connect(incWidget,SIGNAL(isCalculate()),this,SLOT(isCalculateCarton()));
    connect(incWidget,SIGNAL(finishedCalc(QString)),this,SLOT(finishedCalcCarton()));

    FactorialWidget *factorialWidget = new FactorialWidget;
    rightWidget->addWidget(factorialWidget);
    connect(factorialWidget->btn_calculate,SIGNAL(clicked(bool)),factorialWidget,SLOT(calculate()));

    PrimeWidget *primeWidget = new PrimeWidget;
    rightWidget->addWidget(primeWidget);
    connect(primeWidget->btn_calculate,SIGNAL(clicked(bool)),primeWidget,SLOT(calculate()));

    rightWidget->hide();

    connect(btn_quit,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    emit outOfLeftItem();
}

void MainWindow::changeLeftWidget(QModelIndex index)
{
    rightWidget->setCurrentIndex(index.row());
    rightWidget->show();
}

void MainWindow::EnterLeftItem(QModelIndex index)
{
    QStandardItem *item = model->itemFromIndex(index);
    if(highLightItem != item)
    {
        if(highLightItem != nullptr)
            highLightItem->setBackground(*normalBg);
        item->setBackground(*highLightBg);
        highLightItem = item;
    }
}

void MainWindow::OuterLeftItem()
{
    if(highLightItem != nullptr)
    {
        highLightItem->setBackground(*normalBg);
        highLightItem = nullptr;
    }
}

void MainWindow::isCalculateCarton()
{
    m_circleWidget->setLoading();
    this->setEnabled(false);
}

void MainWindow::finishedCalcCarton()
{
    m_circleWidget->setNoLoading();
    this->setEnabled(true);
}

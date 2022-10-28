#include "incwidget.h"
#include "circlewidget.h"
#include "mybutton.h"
#include "myqgsettings.h"
#include <QDebug>
#include <QThread>
#include <QDBusPendingReply>
#include <thread>

IncWidget::IncWidget(QWidget *parent):
    QWidget(parent),
    param1(nullptr),
    param2(nullptr),
    result(nullptr),
    btn_calculate(nullptr),
    layout(nullptr)
{
    createGUI();
    interfaceAdapter = new DBusInterfaceAdapter(
                "yuan.task.func",
                "/yuan/task/func",
                "yuan.task.func");
    connect(this,SIGNAL(finishedCalc(QString)),this,SLOT(changeResult(QString)));
}

void IncWidget::createGUI()
{
    param1 = new QLineEdit;
    param2 = new QLineEdit;
    result = new QLineEdit;
    btn_calculate = new QPushButton;
    layout = new QGridLayout(this);

    param1->setPlaceholderText("参数1");
    param2->setPlaceholderText("参数2");
    result->setPlaceholderText("结果");
    result->setEnabled(false);
    btn_calculate->setText("计算");

    layout->addWidget(param1,1,0,1,1);
    layout->addWidget(param2,1,1,1,1);
    layout->addWidget(result,2,0,1,2);
    layout->addWidget(btn_calculate,3,0,1,2);
}

static void _calculate(IncWidget *inc)
{
    QVariant v1(inc->param1->text().toInt());
    QVariant v2(inc->param2->text().toInt());
    QDBusReply<int> reply = inc->interfaceAdapter->m_inter->call("add",v1,v2);
    if(reply.isValid())
    {
        QString res = QString::number(reply.value());
        emit inc->finishedCalc(res);
    }
}

void IncWidget::calculate()
{
    bool serverRunning = MyQGSettings::get_instance()->get("serverrun").toBool();
    if(serverRunning == false)
    {

    }


    emit isCalculate();
    std::thread t(_calculate,this);
    t.detach();
}

void IncWidget::changeResult(QString res)
{
    result->setText(res);
}

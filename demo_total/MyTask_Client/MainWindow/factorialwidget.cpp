#include "factorialwidget.h"
#include <QDebug>

FactorialWidget::FactorialWidget(QWidget *parent) :
    QWidget(parent),
    param(new QLineEdit),
    result(new QLineEdit),
    btn_calculate(new QPushButton),
    layout(new QGridLayout(this))
{
    createGUI();
    interfaceAdapter = new DBusInterfaceAdapter(
                "yuan.task.func",
                "/yuan/task/func",
                "yuan.task.func");
}

void FactorialWidget::createGUI()
{
    param->setPlaceholderText("参数");
    result->setPlaceholderText("结果");
    btn_calculate->setText("计算");

    layout->addWidget(param,0,0,1,1);
    layout->addWidget(result,1,0,1,1);
    layout->addWidget(btn_calculate,2,0,1,1);
}

void FactorialWidget::calculate()
{
    QVariant v(param->text().toInt());
    QDBusReply<int> reply = interfaceAdapter->m_inter->call("factorial",v);
    if(reply.isValid())
    {
        result->setText(QString::number(reply.value()));
    }
}

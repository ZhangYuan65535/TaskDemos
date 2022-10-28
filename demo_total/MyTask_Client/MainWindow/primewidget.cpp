#include "primewidget.h"

PrimeWidget::PrimeWidget(QWidget *parent):
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
}

void PrimeWidget::createGUI()
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

    layout->addWidget(param1,0,0,1,1);
    layout->addWidget(param2,0,1,1,1);
    layout->addWidget(result,1,0,1,2);
    layout->addWidget(btn_calculate,2,0,1,2);
}

void PrimeWidget::calculate()
{
    QVariant v1(param1->text().toInt());
    QVariant v2(param2->text().toInt());
    QDBusReply<int> reply = interfaceAdapter->m_inter->call("prime",v1,v2);
    if(reply.isValid())
    {
        result->setText(QString::number(reply.value()));
    }
}

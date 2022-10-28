#include "mydbusadapter.h"

MyDBusAdapter::MyDBusAdapter(QObject *parent):
    QDBusAbstractAdaptor(parent),
    calcStrategy(nullptr)
{

}

int MyDBusAdapter::inc(int n)
{
    return parent()->inc(n);
}

int MyDBusAdapter::prime(int begin, int end)
{
    return parent()->prime(begin,end);
}

int MyDBusAdapter::add(int param1, int param2)
{
    calcStrategy = new CalcAdd();
    QList<int> list;
    list<<param1<<param2;
    QVariant v = QVariant::fromValue<QList<int>>(list);
    calcStrategy->setParam(v);
    int result = calcStrategy->calculate();
    return result;

}

int MyDBusAdapter::factorial(int param)
{
    calcStrategy = new CalcFactorial();
    QVariant v;
    v.setValue(param);
    calcStrategy->setParam(v);
    int result = calcStrategy->calculate();
    qWarning()<<result;
    return result;
}

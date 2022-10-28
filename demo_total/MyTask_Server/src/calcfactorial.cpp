#include "calcfactorial.h"
#include <QDebug>

struct CalcFactorialPrivate
{
    CalcFactorialPrivate(){}
    int param;
};

CalcFactorial::CalcFactorial(QObject *parent):
    QObject(parent),
    d_ptr(new CalcFactorialPrivate())
{

}

int CalcFactorial::calculate()
{
    Q_D(CalcFactorial);

    int sum = 0;
    int value = d->param;
    while(value)
    {
        sum += value;
        value--;
    }
    return sum;
}

void CalcFactorial::setParam(QVariant val)
{
    Q_D(CalcFactorial);
    d->param = val.toInt();
}


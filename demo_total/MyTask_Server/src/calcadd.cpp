#include "calcadd.h"
#include <QList>
#include <QDebug>
#include <QThread>

struct CalcAddPrivate
{
    CalcAddPrivate() {}
    int param1;
    int param2;
};

CalcAdd::CalcAdd(QObject *parent):
    QObject(parent),
    d_ptr(new CalcAddPrivate())
{
    
}

int CalcAdd::calculate()
{
    Q_D(CalcAdd);
    QThread::sleep(3);
    return d->param1 + d->param2;
}

void CalcAdd::setParam(QVariant val)
{
    Q_D(CalcAdd);
    QList<int> list = val.value<QList<int>>();
    d->param1 = list.at(0);
    d->param2 = list.at(1);
}



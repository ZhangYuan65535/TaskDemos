#ifndef CALCADD_H
#define CALCADD_H

#include "calcstrategy.h"
#include <QObject>

class CalcAddPrivate;
class CalcAdd:public QObject, public CalcStrategy
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(CalcAdd)
public:
    explicit CalcAdd(QObject *parent = nullptr);
    virtual int calculate() override;
    virtual void setParam(QVariant val);
private:
    CalcAddPrivate* d_ptr;
};

#endif // CALCADD_H

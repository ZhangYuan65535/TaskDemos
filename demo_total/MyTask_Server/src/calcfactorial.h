#ifndef CALCSUB_H
#define CALCSUB_H

#include "calcstrategy.h"
#include <QObject>

class CalcFactorialPrivate;
class CalcFactorial:public QObject,public CalcStrategy
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(CalcFactorial)
public:
    explicit CalcFactorial(QObject *parent = nullptr);
    virtual int calculate() override;
    virtual void setParam(QVariant val);
private:
    CalcFactorialPrivate* d_ptr;
};

#endif // CALCSUB_H

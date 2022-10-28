#ifndef CALCSTRATEGY_H
#define CALCSTRATEGY_H

#include <QVariant>

class CalcStrategy
{
public:
    virtual int calculate()=0;
    virtual void setParam(QVariant val)=0;
    virtual ~CalcStrategy(){}
};

#endif // CALCSTRATEGY_H

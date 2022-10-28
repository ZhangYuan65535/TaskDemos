#ifndef PRIMECALCSUB_H
#define PRIMECALCSUB_H

#include "calcbase.h"
#include <QVariant>

class PrimeCalcSub:public CalcBase
{
    Q_OBJECT
public:
    PrimeCalcSub(int param1,int param2,CalcBase* parent = nullptr);
    virtual void calculate();
public slots:
    void threadFinished(QList<int>);
private:
    QVariant m_result;
    bool resIsValid;
    int m_param1;
    int m_param2;
};

#endif // PRIMECALCSUB_H

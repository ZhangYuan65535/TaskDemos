#ifndef ADDCALCSUB_H
#define ADDCALCSUB_H

#include "calcbase.h"
#include <QObject>

class AddCalcSubPrivate;
class AddCalcSub : public CalcBase
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(AddCalcSub)
public:
    explicit AddCalcSub(int param1,int param2,CalcBase *parent = nullptr);
    ~AddCalcSub();
    virtual void calculate();
private:
    AddCalcSubPrivate* d_ptr;

};

#endif // ADDCALCSUB_H

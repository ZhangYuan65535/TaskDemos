#include "addcalcsub.h"
#include <QVariant>
#include <QList>
#include <QDebug>

struct AddCalcSubPrivate
{
    AddCalcSubPrivate(int param1,int param2,AddCalcSub* parent):
        q_ptr(parent),
        m_param1(param1),
        m_param2(param2)
    {

    }
    ~AddCalcSubPrivate(){}

    Q_DECLARE_PUBLIC(AddCalcSub)
    AddCalcSub *q_ptr;
    int m_param1;
    int m_param2;
};

AddCalcSub::AddCalcSub(int param1, int param2, CalcBase *parent):
    CalcBase(parent),
    d_ptr(new AddCalcSubPrivate(param1,param2,this))
{

}

AddCalcSub::~AddCalcSub()
{
    delete d_ptr;
}

void AddCalcSub::calculate()
{
    Q_D(AddCalcSub);
    QVariant val(d->m_param1+d->m_param2);
    emit CalcBase::sig_resultPrepared(val);
}

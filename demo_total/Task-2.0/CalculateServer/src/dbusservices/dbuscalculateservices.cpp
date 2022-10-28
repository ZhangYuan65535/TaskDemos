#include "dbuscalculateservices.h"
#include "addcalcsub.h"

DBusCalculateServices::DBusCalculateServices(QObject *parent) :
    QObject(parent),
    m_calculate(nullptr)
{

}

void DBusCalculateServices::add(int param1, int param2)
{
    m_calculate = new AddCalcSub(param1,param2,this);
    connect(calc,SIGNAL(sig_resultPrepared(QVariant)),this,SIGNAL(calculateFinished(QVariant)));
    m_calculate->calculate();
}

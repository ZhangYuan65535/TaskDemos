#include "primecalcsub.h"
#include "controller.h"
#include <QVariant>
#include <QDebug>

PrimeCalcSub::PrimeCalcSub(int param1,int param2,CalcBase *parent):
    m_param1(param1),
    m_param2(param2),
    CalcBase(parent)
{

}

void PrimeCalcSub::threadFinished(QList<int> list)
{
    m_result.fromValue<QList<int>>(list);
    resIsValid = true;
    emit sig_resultPrepared(QVariant::fromValue<QList<int>>(list));
}

void PrimeCalcSub::calculate()
{
    resIsValid = false;
    Controller *controller = new Controller(m_param1,m_param2,this);
    QObject::connect(controller,&Controller::endRunning,this,&PrimeCalcSub::threadFinished);
    controller->start();
    controller->waitSonThread();
    qWarning()<<"运算完成";
}

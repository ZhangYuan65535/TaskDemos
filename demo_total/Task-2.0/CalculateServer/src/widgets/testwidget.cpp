#include "testwidget.h"
#include "addcalcsub.h"
#include "primecalcsub.h"

#include <QDebug>

TestWidget::TestWidget(QWidget *parent) : QWidget(parent)
{
//    CalcBase *b = new PrimeCalcSub(1,10);
//    connect(b,SIGNAL(sig_resultPrepared(QVariant)),this,SLOT(test(QVariant)));
//    b->calculate();

    CalcBase *b = new AddCalcSub(2,3);
    connect(b,SIGNAL(sig_resultPrepared(QVariant)),this,SLOT(test(QVariant)));
    b->calculate();

}

void TestWidget::test(QVariant val)
{
    qWarning()<<val.toInt();
}

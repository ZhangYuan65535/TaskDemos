#include "primeworker.h"
#include <QDebug>

PrimeWorker::PrimeWorker(QObject *parent) : QObject(parent)
{

}

static bool _isPrime(int n)
{
    if(n==0 || n==1 || n==2)
        return false;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

void PrimeWorker::on_doSomething()
{
    QList<int> result;
    for(auto i:*list)
    {
        if(_isPrime(i))
        {
            result<<i;
        }
    }
    emit resultReady(result);
}

#include "primetask.h"

PrimeTask::PrimeTask(int num, QObject *parent):
    QObject(parent),
    m_num(num)
{

}

void PrimeTask::run()
{
    if(m_num == 0 || m_num == 1 || m_num == 2){
        return;
    }else{
        for(int i = 2; i < m_num / 2; i++){
            if(m_num % 2 == 0)
                return;
        }
        emit isPrime(m_num);
    }
}

#include "workthread.h"
#include <QDebug>

void WorkThread::run()
{

    for(int num = m_start; num <= m_end; num++){
        if(num == 0 || num == 1 || num == 2){
            continue;
        }else{
            bool flag = true;
            for(int i = 2; i < num / 2; i++){
                if(num % 2 == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                list.append(num);
            }
        }
    }
    emit resultReady(list);
}

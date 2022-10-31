#ifndef WORKER_H
#define WORKER_H

#include <QObject>

/**
 * @brief The Worker class 任务类，用于测试第一种多线程的写法
 * 为方便起见，直接在头文件中实现函数定义
 */
class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(){}
public slots:
    void doWork(){
        list.clear();
        for(int num = 1; num <= 100; num++){
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

    void doWork2(){
        list.clear();
        list << 1 << 2 << 3 << 4;
        emit resultReady(list);
    }

signals:
    void resultReady(QList<int>);
private:
    QList<int> list;
};

#endif // WORKER_H

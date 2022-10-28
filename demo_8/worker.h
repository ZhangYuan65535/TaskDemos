#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(){}
public slots:
    void doWork(){
        list.clear();
        for(int num = 100; num <= 200; num++){
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

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include "primeworker.h"
#define THREADS 8
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(int param1,int param2,QObject *parent = nullptr);
    ~Controller();
    void start();
    void waitSonThread();
signals:
    void startRunning();
    void endRunning(QList<int>);
public slots:
    void on_receiveResult(QList<int>);
private:
public:
    QThread* m_threadList[THREADS];
    PrimeWorker* m_workerList[THREADS];
    QList<int> Lists[THREADS];
    QList<int> m_result;
    int finished;
};

#endif // CONTROLLER_H

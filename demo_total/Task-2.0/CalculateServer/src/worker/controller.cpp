#include "controller.h"
#include <QDebug>

Controller::Controller(int param1,int param2,QObject *parent) : QObject(parent)
{
    finished = 0;
    int index=0;
    for(int i=0;i<THREADS;i++)
    {
        m_threadList[i] = new QThread;
    }
    for(int i=param1;i<param2;i++)
    {
        Lists[index].append(i);
        index = (index+1)%THREADS;
    }
    for(int i=0;i<THREADS;i++)
    {
        m_workerList[i] = new PrimeWorker();
        m_workerList[i]->list = &Lists[i];
        m_workerList[i]->moveToThread(m_threadList[i]);
        connect(this, &Controller::startRunning, m_workerList[i], &PrimeWorker::on_doSomething);
        connect(m_threadList[i], &QThread::finished, m_workerList[i], &QObject::deleteLater);
        connect(m_workerList[i], &PrimeWorker::resultReady, this, &Controller::on_receiveResult);
        m_threadList[i]->start();
    }

}

Controller::~Controller()
{
    qWarning()<<"控制线程结束";
}

void Controller::start()
{
    emit startRunning();
}

void Controller::waitSonThread()
{
    for(int i=0;i<THREADS;i++)
    {
        m_threadList[i]->quit();
        m_threadList[i]->wait();
    }
}

void Controller::on_receiveResult(QList<int> list)
{
    m_result<<list;
    finished++;
    if(finished == THREADS)
    {
        emit endRunning(m_result);
    }
}


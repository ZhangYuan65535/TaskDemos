#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QObject>
#include <QThread>

/**
 * @brief The WorkThread class 任务类，用于测试 QThread 多线程写法
 */
class WorkThread: public QThread
{
    Q_OBJECT
public:
    WorkThread(int start,int end):
        m_start(start),
        m_end(end)
    {

    }

    void run();
signals:
    void resultReady(QList<int>);
private:
    int m_start;
    int m_end;
    QList<int> list;
};

#endif // WORKTHREAD_H

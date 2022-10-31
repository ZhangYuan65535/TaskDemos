#ifndef PRIMETASK_H
#define PRIMETASK_H

#include <QObject>
#include <QRunnable>

/**
 * @brief The PrimeTask class 任务类，用于实现线程池
 */
class PrimeTask : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit PrimeTask(int num, QObject *parent = nullptr);
    ~PrimeTask(){}

protected:
    void run();
signals:
    void isPrime(int);

private:
    int m_num;
};

#endif // PRIMETASK_H

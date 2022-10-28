#ifndef PRIMEWORKER_H
#define PRIMEWORKER_H

#include <QObject>

class PrimeWorker : public QObject
{
    Q_OBJECT
public:
    explicit PrimeWorker(QObject *parent = nullptr);
    QList<int> *list;
signals:
    void resultReady(const QList<int>);
public slots:
    void on_doSomething();
};

#endif // PRIMEWORKER_H

#ifndef CALCBASE_H
#define CALCBASE_H

#include <QObject>
#include <QVariant>

class CalcBase : public QObject
{
    Q_OBJECT
public:
    explicit CalcBase(QObject *parent = nullptr);
    virtual ~CalcBase();

    virtual void calculate() = 0;
signals:
    void sig_resultPrepared(QVariant);
};

#endif // CALCBASE_H

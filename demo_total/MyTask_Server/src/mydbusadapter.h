#ifndef MYDBUSADAPTER_H
#define MYDBUSADAPTER_H

#include "functions.h"
#include "calcadd.h"
#include "calcfactorial.h"
#include <qt5/QtDBus/QtDBus>
#include <qt5/QtCore/QObject>

class MyDBusAdapter:public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","yuan.task.func")
public:
    explicit MyDBusAdapter(QObject* parent);
    inline Functions* parent() const
    {
        return static_cast<Functions*>(QObject::parent());
    }

public slots:
    int inc(int n);
    int prime(int begin,int end);
    int add(int param1,int param2);
    int factorial(int param);
private:
    CalcStrategy *calcStrategy;
};

#endif // MYDBUSADAPTER_H

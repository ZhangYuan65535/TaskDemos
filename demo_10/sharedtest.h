#pragma once

#include <QSharedPointer>
#include <QWeakPointer>
#include <QDebug>
#include <QObject>
#include <QWidget>

class SharedTest
{
public:
    SharedTest(){ qWarning() << str << "ctor"; }
    ~SharedTest(){ qWarning() << str <<"dtor"; }

    QSharedPointer<SharedTest> sp;
    const QString str = "SharedTest";
};

class WeakTest
{
public:
    WeakTest(){ qWarning() << str << "ctor"; }
    ~WeakTest(){ qWarning() << str << "dtor"; }

    QWeakPointer<WeakTest> sp;
    const QString str = "WeakTest";
};

class PointerTest: public QWidget
{
public:
    PointerTest(){ qWarning() << str << "ctor"; }
    ~PointerTest(){ qWarning() << str << "dtor"; }

    const QString str = "PointerTest";
};

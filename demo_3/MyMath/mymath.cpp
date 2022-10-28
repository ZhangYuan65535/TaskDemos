#include "mymath.h"

struct MyMathPrivate
{
    MyMathPrivate(){}
    ~MyMathPrivate(){}

    int param1;
    int param2;
};

MyMath::MyMath(QObject *parent) :
    QObject(parent),
    d_ptr(new MyMathPrivate)
{

}

MyMath::~MyMath()
{
    delete d_ptr;
}

void MyMath::setParam(int p1, int p2)
{
    Q_D(MyMath);
    d->param1 = p1;
    d->param2 = p2;
}


int MyMath::add()
{
    Q_D(MyMath);
    return d->param1 + d->param2;
}

double MyMath::getData()
{
    return d4+d5+d6;
}


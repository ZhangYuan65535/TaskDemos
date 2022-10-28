#include <QCoreApplication>
#include <QDebug>
#include "MyMath/mymath.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    MyMath m;
//    m.setParam(3,4);
//    qWarning() << m.add();

    MyMath m;
//    m.getData();

    return a.exec();
}

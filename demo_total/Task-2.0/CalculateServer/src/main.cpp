#include "calculatesys.h"
#include "primecalcsub.h"
#include "testwidget.h"
#include "dbuscalculateservices.h"
#include <QApplication>
#include <QDebug>
#include <QSharedPointer>
#include <QDBus

int main(int argc,char **argv)
{
    QApplication app(argc,argv);




    return app.exec();
}

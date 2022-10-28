#include "widget.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QDBusInterface interface(
//                "yuan.task.func",
//                "/yuan/task/func",
//                "yuan.task.func",
//                QDBusConnection::sessionBus());
//    QVariant var1,var2;
//    var1.setValue(1);
//    var2.setValue(11);
//    QDBusReply<int> reply = interface.call("prime",var1,var2);
//    if(reply.isValid())
//        qWarning()<<reply.value();
    MainWindow w;
    w.show();

    return a.exec();
}

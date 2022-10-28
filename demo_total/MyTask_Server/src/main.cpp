#include "mydbusadapter.h"
#include "functions.h"
#include <iostream>
#include <QDebug>
#include <QApplication>
#include <QGSettings>

#include <QPluginLoader>

#include "calcadd.h"
#include "calcfactorial.h"

using namespace std;

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    Functions func;
    MyDBusAdapter service(&func);
    QDBusConnection conn = QDBusConnection::sessionBus();
    if (!conn.registerService("yuan.task.func") ||
            !conn.registerObject("/yuan/task/func", &func)) {
        qWarning() << "register dbus service failed";
    }

    QGSettings *setting = new QGSettings(
                "yuan.task.value",
                "/yuan/task/value/");
    qWarning()<<setting->get("serverrun").toBool();
    setting->set("serverrun",QVariant(true));

    return app.exec();
}

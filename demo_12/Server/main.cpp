#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>

#include "provideservice.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QString service("com.yuan.task.demo12");
    QString path("/com/yuan/task/demo12");

    QDBusConnection conn = QDBusConnection::sessionBus();
    if (!conn.registerService(service)) {
        qWarning() << "error:" << conn.lastError().message();
        exit(-1);
    }
    ProvideService p;
    conn.registerObject(path, &p, QDBusConnection::ExportAllContents);

    return app.exec();
}

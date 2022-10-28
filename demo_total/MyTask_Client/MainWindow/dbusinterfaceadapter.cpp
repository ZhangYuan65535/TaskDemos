#include "dbusinterfaceadapter.h"

DBusInterfaceAdapter::DBusInterfaceAdapter(QString server, QString path, QString interface)
{
    m_inter.reset(new QDBusInterface(server,path,interface,QDBusConnection::sessionBus()));
    if(!m_inter->isValid())
    {
        qWarning()<<qPrintable(QDBusConnection::sessionBus().lastError().message());
        exit(1);
    }
}

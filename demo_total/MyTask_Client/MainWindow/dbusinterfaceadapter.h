#ifndef DBUSINTERFACEADAPTER_H
#define DBUSINTERFACEADAPTER_H

#include <QDBusInterface>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>
#include <QDebug>
#include <QScopedPointer>

class DBusInterfaceAdapter
{
public:
    DBusInterfaceAdapter(QString server,QString path,QString interface);

public:
    QScopedPointer<QDBusInterface> m_inter;
};

#endif // DBUSINTERFACEADAPTER_H

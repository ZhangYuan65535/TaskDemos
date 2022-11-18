#include <QMetaType>
#include <QDBusPendingReply>

#include "deviceinterface.h"

static const QString service("com.yuan.task.demo12");
static const QString path("/com/yuan/task/demo12");
static const QString interface("com.yuan.task.demo12");

DeviceInterface::DeviceInterface(QObject *parent):
    QObject(parent),
    m_inter(new QDBusInterface(service, path, interface, QDBusConnection::sessionBus(), this))
{

}

quint32 DeviceInterface::id()
{
    QDBusPendingReply<quint32> reply = m_inter->asyncCall("id");
    reply.waitForFinished();
    if (reply.isValid()) {
        return reply.value();
    }
    exit(-1);
}

QString DeviceInterface::name()
{
    QDBusPendingReply<QString> reply = m_inter->asyncCall("name");
    reply.waitForFinished();
    if (reply.isValid()) {
        return reply.value();
    }
    exit(-1);
}

QString DeviceInterface::type()
{
    QDBusPendingReply<QString> reply = m_inter->asyncCall("type");
    reply.waitForFinished();
    if (reply.isValid()) {
        return reply.value();
    }
    exit(-1);
}

void DeviceInterface::setId(quint32 id)
{
    m_inter->asyncCallWithArgumentList("setId", {QVariant::fromValue(id)});
}

void DeviceInterface::setName(QString name)
{
    m_inter->asyncCallWithArgumentList("setName", {QVariant::fromValue(name)});
}

void DeviceInterface::setType(QString type)
{
    m_inter->asyncCallWithArgumentList("setType", {QVariant::fromValue(type)});
}

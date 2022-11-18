#include <QMetaType>
#include <QDBusMetaType>

#include "provideservice.h"
#include "provideservice_p.h"

ProvideServicePrivate::ProvideServicePrivate(ProvideService *q):
    q_ptr(q)
{

}

ProvideService::ProvideService(QObject *parent):
    QObject(parent),
    d_ptr(new ProvideServicePrivate(this))
{

}

quint32 ProvideService::id()
{
    Q_D(ProvideService);
    return d->m_id;
}

QString ProvideService::name()
{
    Q_D(ProvideService);
    return d->m_name;
}

QString ProvideService::type()
{
    Q_D(ProvideService);
    return d->m_type;
}

void ProvideService::setId(quint32 id)
{
    Q_D(ProvideService);
    d->m_id = id;
}

void ProvideService::setName(QString name)
{
    Q_D(ProvideService);
    d->m_name = name;
}

void ProvideService::setType(QString type)
{
    Q_D(ProvideService);
    d->m_type = type;
}

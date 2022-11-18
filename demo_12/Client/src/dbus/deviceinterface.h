#pragma once

#include <QObject>
#include <QDBusInterface>

class DeviceInterface : public QObject
{
    Q_OBJECT
public:
    DeviceInterface(QObject *parent = nullptr);

    quint32 id();
    QString name();
    QString type();
    void setId(quint32 id);
    void setName(QString name);
    void setType(QString type);

private:
    QDBusInterface *m_inter;

};

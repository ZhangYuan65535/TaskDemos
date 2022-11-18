#pragma once

#include <QObject>

class ProvideServicePrivate;
class ProvideService : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.yuan.task.demo12")

    Q_PROPERTY(quint32 id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)

public:
    ProvideService(QObject *parent = nullptr);

public slots:
    quint32 id();
    QString name();
    QString type();
    void setId(quint32 id);
    void setName(QString name);
    void setType(QString type);

signals:
    void idChanged(quint32 id);
    void nameChanged(QString name);
    void typeChanged(QString type);

private:
    ProvideServicePrivate *d_ptr;
    Q_DECLARE_PRIVATE(ProvideService)
};



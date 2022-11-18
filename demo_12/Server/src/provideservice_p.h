#pragma once

#include "provideservice.h"

class ProvideServicePrivate : public QObject
{
    Q_OBJECT
public:
    ProvideServicePrivate(ProvideService *q);

private:
    quint32 m_id;
    QString m_name;
    QString m_type;

    ProvideService *q_ptr;
    Q_DECLARE_PUBLIC(ProvideService)
};

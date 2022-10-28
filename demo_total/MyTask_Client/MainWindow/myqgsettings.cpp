#include "myqgsettings.h"
#include <QString>
#include <QVariant>

MyQGSettings* MyQGSettings::m_MySetting = nullptr;

MyQGSettings::MyQGSettings()
{
    m_Setting = new QGSettings("yuan.task.value","/yuan/task/value/");
}

MyQGSettings* MyQGSettings::get_instance()
{
    if(m_MySetting == nullptr)
    {
        m_MySetting = new MyQGSettings;
    }
    return m_MySetting;
}

QVariant MyQGSettings::get(QString key)
{
    return m_Setting->get(key);
}

void MyQGSettings::set(QString key, QVariant value)
{
    m_Setting->set(key,value);
}

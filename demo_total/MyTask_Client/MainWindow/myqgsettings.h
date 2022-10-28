#ifndef MYQGSETTINGS_H
#define MYQGSETTINGS_H

#include <QGSettings>

class MyQGSettings
{
private:
    MyQGSettings();
public:
    static MyQGSettings* get_instance();
    QVariant get(QString key);
    void set(QString key,QVariant value);

    static MyQGSettings* m_MySetting;
    QGSettings* m_Setting;
};



#endif // MYQGSETTINGS_H

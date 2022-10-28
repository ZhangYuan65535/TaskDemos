#ifndef DBUSCALCULATESERVICES_H
#define DBUSCALCULATESERVICES_H

#include <QObject>

class Calculate;
class DBusCalculateServices : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","yuan.task.func")
public:
    explicit DBusCalculateServices(QObject *parent = nullptr);
    void add(int param1,int param2);
signals:
    void calculateFinished(QVariant);
private:
    Calculate *m_calculate;
};

#endif // DBUSCALCULATESERVICES_H

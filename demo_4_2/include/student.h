#pragma once

#include <QMap>

#include "baseitem.h"

class Student : public BaseItem
{

public:
    Student(QString name, QString id, QMap<QString,int> score);

    virtual void show() const;
    virtual bool compare(BaseItem *item1, BaseItem *item2) const;
private:
    QString m_name;
    QString m_id;
    QMap<QString, int> m_score;
};

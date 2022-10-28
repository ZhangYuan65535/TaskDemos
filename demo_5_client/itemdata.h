#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <QMetaType>
class ItemData{
public:
    QString name;
    QString age;
    QString phone;
    QString id;
    QString addr;
    QString temp;
};
Q_DECLARE_METATYPE(ItemData)

#endif // ITEMDATA_H

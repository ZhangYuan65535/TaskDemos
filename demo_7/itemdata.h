#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <QMetaType>
class ItemData{
public:
    QString iconPath;
    QString desktopPath;
    QString appName;
};
Q_DECLARE_METATYPE(ItemData)
#endif // ITEMDATA_H

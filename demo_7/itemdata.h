#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <QMetaType>

/**
 * @brief The ItemData class 应用数据类，存放一个应用的详细信息
 */
class ItemData{
public:
    QString iconPath;
    QString desktopPath;
    QString appName;
};
Q_DECLARE_METATYPE(ItemData)
#endif // ITEMDATA_H

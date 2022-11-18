#pragma once

#include <QList>

#include "baseitem.h"

class Model
{
public:
    Model();
    void addItem(BaseItem *item);
    void show();
    void sort();
private:
    QList<BaseItem*> m_itemList;
};

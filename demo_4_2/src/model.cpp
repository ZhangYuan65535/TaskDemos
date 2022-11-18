#include "model.h"

Model::Model()
{

}

void Model::addItem(BaseItem *item)
{
    m_itemList.append(item);
}

void Model::show()
{
    for (BaseItem *item : m_itemList) {
        item->show();
    }
}

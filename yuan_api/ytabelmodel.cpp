#include "ytabelmodel.h"
#include <QDebug>


YTabelModel::YTabelModel(int row, int col, QObject *parent):
    QObject(parent),
    m_row(row),
    m_col(col),
    m_dataList(new DataList)
{
    for(int i = 0; i < row; i++){
        DirectList list;
        for(int j = 0; j < col; j++){
            list.append(QVariant());
        }
        m_dataList->append(list);
    }
}

bool YTabelModel::posIsValid(int row, int col)
{
    if(row >= m_row)
        return false;
    if(col >= m_col)
        return false;
    return true;
}

QVariant YTabelModel::getData(int row, int col)
{
    if(posIsValid(row,col))
        return (*m_dataList)[row][col];
}

bool YTabelModel::setData(int row, int col, QVariant val)
{
    if(posIsValid(row,col)){
        (*m_dataList)[row].replace(col,val);
        return true;
    }
    qWarning() << "插入失败";
    return false;
}

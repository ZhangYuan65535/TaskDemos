#ifndef YTABELMODEL_H
#define YTABELMODEL_H

#include <QObject>

class YTabelModel : public QObject
{
    Q_OBJECT
    using DirectList = QList<QVariant>;
    using DataList = QList<DirectList>;
public:
    explicit YTabelModel(int row,int col,QObject *parent = nullptr);
    bool posIsValid(int row,int col);
    QVariant getData(int row,int col);
    bool setData(int row,int col,QVariant val);

private:
    int m_row;
    int m_col;
    DataList *m_dataList;
};

#endif // YTABELMODEL_H

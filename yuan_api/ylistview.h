#ifndef YLISTVIEW_H
#define YLISTVIEW_H

#include <QWidget>
#include "ytabelmodel.h"

class YListView : public QWidget
{
    Q_OBJECT
public:
    explicit YListView(QWidget *parent = nullptr);

    void setModel(YTabelModel* model,QWidget* widget);

private:
    YTabelModel *m_model;
};

#endif // YLISTVIEW_H

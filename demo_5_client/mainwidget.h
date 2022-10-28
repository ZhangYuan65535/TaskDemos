#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>
#include <QGSettings>
#include "itemdata.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

    void readInfo();

private:
    QStandardItemModel *m_model;
    QTableView *m_view;
    QGSettings *m_settings;
    QList<ItemData> m_list;

};

#endif // MAINWIDGET_H

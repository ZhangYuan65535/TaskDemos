#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QModelIndex>

class QStandardItemModel;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void load();

private:
    QStandardItemModel *m_model;

public slots:
    void deal_clicked(QModelIndex index);
    void deal_addNewApp();
};

#endif // WIDGET_H

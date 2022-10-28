#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    ItemWidget(QString iconPath, QWidget *parent = 0);
    ~ItemWidget();

    void paintEvent(QPaintEvent *e);

private:
    QPixmap icon;
};

#endif // ITEMWIDGET_H

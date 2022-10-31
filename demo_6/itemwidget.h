#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>


/**
 * @brief The ItemWidget class 窗口类，用于放置自绘控件
 */
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

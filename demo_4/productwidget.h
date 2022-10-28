#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>

class ProductWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProductWidget(QString icon,QString name,double price,QWidget *parent = nullptr);
    void init();

private:
    QString m_iconPath;
    QString m_productName;
    double m_price;
};

#endif // PRODUCTWIDGET_H

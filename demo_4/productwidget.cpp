#include "productwidget.h"
#include <QtWidgets>

ProductWidget::ProductWidget(QString icon,QString name,double price,QWidget *parent) :
    QWidget(parent),
    m_iconPath(icon),
    m_productName(name),
    m_price(price)
{
    this->setGeometry(0,0,150,200);
    init();
}

void ProductWidget::init()
{
    QLayout *layout = new QVBoxLayout(this);
    QLabel *iconLabel = new QLabel(this);
    QLabel *textLabel = new QLabel(this);
    layout->addWidget(iconLabel);
    layout->addWidget(textLabel);

    iconLabel->resize(this->size());
    QPixmap pix(m_iconPath);
    QPixmap dest = pix.scaled(QSize(120,200),Qt::IgnoreAspectRatio);
    iconLabel->setPixmap(dest);

    QFont font;
    font.setPointSize(14);
    textLabel->setFont(font);
    textLabel->setText(m_productName + " " + QString::number(m_price,10,2) + "￥");
    textLabel->setAlignment(Qt::AlignCenter);
}

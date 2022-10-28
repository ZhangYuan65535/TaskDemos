#include "itemwidget.h"
#include <QPainter>
#include <QBitmap>

ItemWidget::ItemWidget(QString iconPath, QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(500,500,300,50);
//    setWindowFlags(Qt::FramelessWindowHint);
    icon.load(iconPath);
}

ItemWidget::~ItemWidget()
{

}

void ItemWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QFont font;

    painter.setRenderHint(QPainter::Antialiasing);
    QRect iconRect(15,5,40,40);
    painter.drawPixmap(iconRect,icon);

    QRect textRect(iconRect.right()+ 25,12,200,40);
    font.setPointSize(12);
    painter.setFont(font);
    painter.drawText(textRect,"文本编辑器");


    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(0,192,255,255)));
    QPoint pos(textRect.right() + 5,25);
    painter.drawEllipse(pos,4,4);


}

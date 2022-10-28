#include <QPainter>
#include <QDebug>
#include "tempdelegate.h"
#include "itemdata.h"

const double padding = 30;
const double tempWidth = padding * 4;
const double tempHeight = padding * 8;
const double radius = padding/2;

TempDelegate::TempDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

static bool isHealth(double temp)
{
    if(temp < 37.2)
        return true;
    return false;
}

static bool isDie(double temp)
{
    if(temp > 43)
        return true;
    return false;
}

void TempDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid()){
        painter->save();
        int offsetX = option.rect.x()+5;
        int offsetY = option.rect.y()+5;
        QVariant val = index.data(Qt::UserRole+1);
        ItemData itemdata = val.value<ItemData>();

        double temp = itemdata.temp.toDouble();
        if(temp == 0)
            return;

        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::white);
        painter->drawRect(QRect(offsetX,offsetY,tempWidth,tempHeight));

        painter->setBrush(QBrush(QColor(0,213,255),Qt::SolidPattern));
        painter->drawEllipse(offsetX,offsetY,tempWidth,padding*3);
        painter->drawEllipse(offsetX,offsetY+tempHeight-3*padding,tempWidth,padding*3);
        painter->drawRect(offsetX,offsetY+padding*1.5,tempWidth,tempHeight-3*padding);

        if(isDie(temp)){
            painter->setBrush(Qt::red);
        }else{
            painter->setBrush(Qt::white);
        }
        painter->drawEllipse(offsetX+tempWidth/2-radius/2,offsetY+1.5*padding-radius/2,radius,radius);
        painter->drawRect(offsetX+tempWidth/2-radius/2,offsetY+1.5*padding,radius,tempHeight-3*padding);
        if(isHealth(temp)){
            painter->setBrush(QBrush(Qt::green));
        }
        else{
            painter->setBrush(QBrush(Qt::red));
        }
        painter->drawEllipse(offsetX+tempWidth/2-radius,offsetY+6.5*padding-radius,radius*2,radius*2);

        painter->setPen(Qt::black);
        painter->setBrush(Qt::NoBrush);

        QPointF ql(offsetX+tempWidth/2+radius/2,offsetY+5.5*padding);
        QPointF qr(offsetX+tempWidth/2+radius/2+padding/5,offsetY+5.5*padding);
        for(int i = 0; i < 8; i++){
            painter->drawLine(ql,qr);
            QPointF pt(qr.x()+padding/10,qr.y()+padding/20);
            QFont font;
            font.setPointSizeF(padding/10+5);
            painter->setFont(font);
            painter->drawText(pt,QString::number(35+i));
            qr.rx() -= padding/10;
            for(int j = 0; j < 4; j++){
                ql.ry() -= padding/10;
                qr.ry() -= padding/10;
                painter->drawLine(ql,qr);
            }
            ql.ry() -= padding/10;
            qr.ry() -= padding/10;
            qr.rx() += padding/10;
        }

        double h = (temp - 35) * padding/2;
        painter->setPen(Qt::NoPen);
        if(isHealth(temp)){
            painter->setBrush(QBrush(Qt::green));
        }
        else{
            painter->setBrush(QBrush(Qt::red));
        }
        if(!isDie(temp))
            painter->drawRect(offsetX+tempWidth/2-radius/2,offsetY+5.5*padding-h,radius,6.5*padding-(5.5*padding-h));


        painter->setPen(Qt::black);
        QFont font;
        font.setPointSize(12);
        painter->setFont(font);
        painter->setBrush(Qt::NoBrush);

        offsetX += 140;
        offsetY += 40;
        QRect textRect(offsetX,offsetY,200,30);
        painter->drawText(textRect,"Name : " + itemdata.name);
        textRect.moveTop(textRect.top()+20);
        painter->drawText(textRect,"Age : " + itemdata.age);
        textRect.moveTop(textRect.top()+20);
        painter->drawText(textRect,"Phone : " + itemdata.phone);
        textRect.moveTop(textRect.top()+20);
        painter->drawText(textRect,"Id : " + itemdata.id);
        textRect.moveTop(textRect.top()+20);
        painter->drawText(textRect,"Addr : " + itemdata.addr);
        textRect.moveTop(textRect.top()+20);
        painter->drawText(textRect,"Temp : " + itemdata.temp);


        textRect.moveTopLeft(QPoint(textRect.left()+40,textRect.top()+40));
        font.setPointSize(16);
        painter->setFont(font);
        if(isHealth(temp)){
            painter->setPen(Qt::blue);
            painter->drawText(textRect,"True");
        }
        else{
            painter->setPen(Qt::red);
            painter->drawText(textRect,"False");
        }

        painter->restore();
    }
}

QSize TempDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    return QSize(option.rect.width(),50);
}

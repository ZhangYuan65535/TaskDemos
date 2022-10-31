#include "tempwidget.h"
#include <QPainter>
#include <QtWidgets>
#include <QDebug>

// 下面设置的全局常量用于控制温度计大小
const double padding = 30;
const double tempWidth = padding * 4;
const double tempHeight = padding * 8;
const double radius = padding/2;


TempWidget::TempWidget(QWidget *parent)
    : QWidget(parent),
      m_curTemp(37.2),
      greenBrush(new QBrush(Qt::green)),
      redBrush(new QBrush(Qt::red))
{
    this->setGeometry(0,0,tempWidth + 200,tempHeight);

    // 添加slider控件，便于观察温度计控件的变色效果
    QSlider *slider = new QSlider(this);
    slider->setGeometry(tempWidth+100,padding,40,200);
    slider->setMaximum(450);
    slider->setMinimum(350);
    slider->setValue(372);
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(tempChanged(int)));
}

TempWidget::~TempWidget()
{

}

/**
 * @brief TempWidget::isHealth 判断当前健康状态
 */
bool TempWidget::isHealth()
{
    if(m_curTemp < 37.2)
        return true;
    return false;
}

/**
 * @brief TempWidget::isDie 判断温度是否超过上限值
 */
bool TempWidget::isDie()
{
    if(m_curTemp > 43)
        return true;
    return false;
}

void TempWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(this->rect());

    painter.setBrush(QBrush(QColor(0,213,255),Qt::SolidPattern));
    painter.drawEllipse(0,0,tempWidth,padding*3);
    painter.drawEllipse(0,tempHeight-3*padding,tempWidth,padding*3);
    painter.drawRect(0,padding*1.5,tempWidth,tempHeight-3*padding);

    if(isDie()){
        painter.setBrush(Qt::red);
    }else{
        painter.setBrush(Qt::white);
    }
    painter.drawEllipse(tempWidth/2-radius/2,1.5*padding-radius/2,radius,radius);
    painter.drawRect(tempWidth/2-radius/2,1.5*padding,radius,tempHeight-3*padding);
    if(isHealth()){
        painter.setBrush(*greenBrush);
    }
    else{
        painter.setBrush(*redBrush);
    }
    painter.drawEllipse(tempWidth/2-radius,6.5*padding-radius,radius*2,radius*2);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::NoBrush);

    QPointF ql(tempWidth/2+radius/2,5.5*padding);
    QPointF qr(tempWidth/2+radius/2+padding/5,5.5*padding);
    for(int i = 0; i < 8; i++){
        painter.drawLine(ql,qr);
        QPointF pt(qr.x()+padding/10,qr.y()+padding/20);
        QFont font;
        font.setPointSizeF(padding/10+5);
        painter.setFont(font);
        painter.drawText(pt,QString::number(35+i));
        qr.rx() -= padding/10;
        for(int j = 0; j < 4; j++){
            ql.ry() -= padding/10;
            qr.ry() -= padding/10;
            painter.drawLine(ql,qr);
        }
        ql.ry() -= padding/10;
        qr.ry() -= padding/10;
        qr.rx() += padding/10;
    }

    double h = (m_curTemp - 35) * padding/2;
    painter.setPen(Qt::NoPen);
    if(isHealth()){
        painter.setBrush(*greenBrush);

    }
    else{
        painter.setBrush(*redBrush);
    }
    if(!isDie())
        painter.drawRect(tempWidth/2-radius/2,5.5*padding-h,radius,6.5*padding-(5.5*padding-h));
}

/**
 * @brief TempWidget::tempChanged 槽函数，关联 slider与温度计控件
 * @param temp 当前温度
 */
void TempWidget::tempChanged(int temp)
{
    this->m_curTemp = temp/10.0;
    this->repaint();
}







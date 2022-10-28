#include "circlewidget.h"
#include <QPainter>
#include <math.h>
#include <QDebug>

CircleWidget::CircleWidget(QWidget *parent):
    QFrame(parent),
    m_timerId(startTimer(100)),
    m_times(0),
    m_centrolPos(QPoint(50,50)),
    m_painter(new QPainter),
    isLoading(false)
{
    for(int angle = 0; angle < 360; angle += 45)
    {
        QPoint pos = getPos(angle,40);
        m_PosList<<pos;
    }
    m_PosLevelList << 5 << 6 << 7 << 6 << 5 << 4 << 3 << 4;
    setLoading();
}

CircleWidget::~CircleWidget()
{

}

QPoint CircleWidget::getPos(double angle, double radius)
{
    qreal w=3.1415926/180;
    double x = radius*cos(angle*w) + m_centrolPos.x();
    double y = m_centrolPos.y() - radius*sin(angle*w);
    return QPoint(x,y);
}

void CircleWidget::setLoading()
{
    isLoading = true;
}

void CircleWidget::setNoLoading()
{
    isLoading = false;
}

void CircleWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    int width=this->width();
    int height=this->height();
    painter.setPen(Qt::NoPen);
    if(isLoading)
        painter.setBrush(QBrush(QColor(99,99,99,99)));
    else
        painter.setBrush(QBrush(QColor(0,0,0,0)));

    for(int i=0;i<8;i++)
    {
        QPoint pos = m_PosList[i];
        int posLevel = m_PosLevelList[i];
        painter.drawEllipse(pos,posLevel,posLevel);
    }
}

void CircleWidget::timerEvent(QTimerEvent *e)
{
    for(int i=0;i<8;i++)
    {
        int level = (m_PosLevelList[i]+1)%8;
        if(level<3)
            level+=3;
        m_PosLevelList[i] = level;
    }
    update();
}



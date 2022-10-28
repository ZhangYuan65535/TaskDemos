#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QFrame>
#include <QTimer>
#include <QPainter>

class CircleWidget : public QFrame
{
    Q_OBJECT
public:
    CircleWidget(QWidget *parent = nullptr);
    ~CircleWidget();
    QPoint getPos(double angle,double radius);
    void setLoading();
    void setNoLoading();
private:
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);
public:
    int m_timerId;
    int m_times;

    QPoint m_centrolPos;
    QList<QPoint> m_PosList;
    QList<int> m_PosLevelList;
    QPainter *m_painter;

    bool isLoading;
};

#endif // CIRCLEWIDGET_H

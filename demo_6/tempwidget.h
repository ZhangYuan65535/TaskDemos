#ifndef TEMPWIDGET_H
#define TEMPWIDGET_H

#include <QWidget>


/**
 * @brief The TempWidget class 自绘控件类，实现温度计GUI功能
 */
class TempWidget : public QWidget
{
    Q_OBJECT
public:
    TempWidget(QWidget *parent = 0);
    ~TempWidget();

    bool isHealth();
    bool isDie();
    void paintEvent(QPaintEvent *event);
public slots:
    void tempChanged(int temp);

private:
    double m_curTemp;       // 当前温度
    QBrush *greenBrush;     // 温度计颜色
    QBrush *redBrush;

};

#endif // TEMPWIDGET_H

#ifndef ROUNDBUTTON_H
#define ROUNDBUTTON_H

#include <QPushButton>
#include <QWidget>

/**
 * @brief The RoundButton class 自定义的按钮类，
 * 将按钮外形改为圆形，
 * 重写了鼠标按下与鼠标释放事件处理函数，
 * 在构造函数中修改自己的 objectName 属性,对上提供支持
 */
class RoundButton:public QPushButton
{
    Q_OBJECT
public:
    RoundButton(int width,int height,QString text, QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // ROUNDBUTTON_H

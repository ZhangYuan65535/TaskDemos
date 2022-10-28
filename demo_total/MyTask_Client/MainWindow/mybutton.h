#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class MyButton:public QPushButton
{
public:
    MyButton(QString iconPath,QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // MYBUTTON_H

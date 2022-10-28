#include "mybutton.h"
#include <QPushButton>
#include <QDebug>
#include <math.h>

MyButton::MyButton(QString iconPath, QWidget *parent):
    QPushButton(parent)
{
    this->setIcon(QIcon(iconPath));
    this->setFixedSize(60,60);
    this->setStyleSheet("QPushButton{"
                        "border-radius:50px;"
                        "border-color:purple"
                        "}");
    this->setIconSize(QSize(50,50));
}

void MyButton::mousePressEvent(QMouseEvent *e)
{
    int posX = e->pos().x();
    int posY = e->pos().y();
    qWarning()<<posX<<posY;
    if(pow(posX-30,2)+pow(posY-30,2) <= 25*25)
    {
        this->setFixedSize(60,60);
        this->setStyleSheet("QPushButton{"
                            "border-radius:60px;"
                            "}");
        this->setIconSize(QSize(60,60));
        return QPushButton::mousePressEvent(e);
    }

}

void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    int posX = e->pos().x();
    int posY = e->pos().y();

    if(pow(posX-30,2)+pow(posY-30,2) <= 25*25)
    {
        this->setFixedSize(60,60);
        this->setStyleSheet("QPushButton{"
                            "border-radius:50px;"
                            "}");
        this->setIconSize(QSize(50,50));
        emit QPushButton::clicked(true);
        return QPushButton::mousePressEvent(e);
    }
}



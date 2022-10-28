#include "roundbutton.h"
#include <QDebug>

RoundButton::RoundButton(int width, int height, QString text, QWidget *parent):
    QPushButton(parent)
{
    this->setFixedSize(width,height);
    this->setStyleSheet("QPushButton{"
                        "border-radius:30px;"
                        "background-color:rgb(211,211,211);"
                        "}");
    this->setText(text);
    this->setObjectName(text);
}

void RoundButton::mousePressEvent(QMouseEvent *event)
{
    this->setStyleSheet("QPushButton{"
                        "border-radius:30px;"
                        "background-color:rgb(168,168,168);"
                        "}");
    return QPushButton::mousePressEvent(event);
}

void RoundButton::mouseReleaseEvent(QMouseEvent *event)
{
    this->setStyleSheet("QPushButton{"
                        "border-radius:30px;"
                        "background-color:rgb(211,211,211);"
                        "}");
    return QPushButton::mouseReleaseEvent(event);
}

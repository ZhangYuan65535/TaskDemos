#include "findedit.h"

FindEdit::FindEdit(QWidget *parent):
    QWidget(parent)
{
    this->setGeometry(0,0,400,50);

    label = new QLabel(this);
    label->setGeometry(this->geometry());
    label->setText("搜索");
    label->setAlignment(Qt::AlignCenter);
}

#ifndef FINDEDIT_H
#define FINDEDIT_H

#include <QtWidgets>

class FindEdit:public QWidget
{
public:
    FindEdit(QWidget *parent = nullptr);

private:
    QLabel *label;


};

#endif // FINDEDIT_H

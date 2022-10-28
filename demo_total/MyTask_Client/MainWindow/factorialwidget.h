#ifndef FACTORIALWIDGET_H
#define FACTORIALWIDGET_H

#include <dbusinterfaceadapter.h>
#include <QWidget>
#include <QtWidgets>
#include <QMouseEvent>

class FactorialWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FactorialWidget(QWidget *parent = nullptr);
    void createGUI();
public slots:
    void calculate();
public:
    QLineEdit *param;
    QLineEdit *result;
    QPushButton *btn_calculate;
    QGridLayout *layout;

    DBusInterfaceAdapter *interfaceAdapter;
};

#endif // FACTORIALWIDGET_H

#ifndef INCWIDGET_H
#define INCWIDGET_H

#include "dbusinterfaceadapter.h"
#include "mybutton.h"
#include <QWidget>
#include <QtWidgets>
#include <QGridLayout>
#include <QObject>

class IncWidget;
static void _calculate(IncWidget *inc);
class IncWidget:public QWidget
{
    Q_OBJECT
public:
    IncWidget(QWidget *parent = nullptr);
    void createGUI();
    ~IncWidget() = default;
    friend void _calculate();
public slots:
    void calculate();
    void changeResult(QString);
signals:
    void isCalculate();
    void finishedCalc(QString);
public:
    QLineEdit *param1;
    QLineEdit *param2;
    QLineEdit *result;
    QPushButton *btn_calculate;

    QGridLayout *layout;

    DBusInterfaceAdapter *interfaceAdapter;
};

#endif // INCWIDGET_H

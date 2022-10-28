#ifndef PRIMEWIDGET_H
#define PRIMEWIDGET_H

#include "dbusinterfaceadapter.h"
#include <QWidget>
#include <QtWidgets>
#include <QGridLayout>
#include <QObject>

class PrimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PrimeWidget(QWidget *parent = nullptr);
    void createGUI();
public slots:
    void calculate();
public:
    QLineEdit *param1;
    QLineEdit *param2;
    QLineEdit *result;
    QPushButton *btn_calculate;
    QGridLayout *layout;

    DBusInterfaceAdapter *interfaceAdapter;
};

#endif // PRIMEWIDGET_H

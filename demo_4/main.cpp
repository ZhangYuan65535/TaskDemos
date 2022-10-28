#include "widget.h"
#include <QApplication>

#include <QDebug>
#include "redtea.h"
#include "greentea.h"
#include "pudding.h"
#include "redbean.h"
#include "detailwindow.h"
#include "productwidget.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

//    RedTea redTea;
//    Pudding pudding(&redTea);
//    RedBean redBean(&pudding);
//    qWarning() << redBean.cost();

    MainWindow w;
    w.show();

//    ProductWidget w(":/Icons/milk_tea.jpg","红茶",12);
//    w.show();

    return a.exec();
}

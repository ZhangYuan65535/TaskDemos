#include "itemwidget.h"
#include "tempwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    TempWidget t;
    t.show();

    return a.exec();
}

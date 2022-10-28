#include "itemwidget.h"
#include "findedit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ItemWidget w(":/Images/typora.png");
//    w.show();

    FindEdit f;
    f.show();

    return a.exec();
}

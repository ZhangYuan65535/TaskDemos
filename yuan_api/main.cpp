#include "widget.h"
#include "ytabelmodel.h"
#include "ylistview.h"
#include "testwidget.h"
#include <QApplication>
#include <QDebug>

template<class T>
class Car:public QWidget{
    Q_OBJECT
public:
    T a;
    Car();
};
template<class T>
Car<T>::Car(){

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    YTabelModel model(1,2);
    model.setData(0,0,1);

    YListView view;
    TestWidget t;
    QWidget q;
//    view.setModel(&model,&q);
    view.setModel(&model,&t);

    return a.exec();
}

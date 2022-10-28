#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbusinterfaceadapter.h"
#include "circlewidget.h"
#include "mybutton.h"
#include <QListView>
#include <QWidget>
#include <QStandardItemModel>
#include <QGridLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
#include <QBrush>

class  MyListView;
class QStackedWidget;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void loadModel();
    void createGUI();
    void mouseMoveEvent(QMouseEvent *e);

private:
    QListView *leftWidget;
    QGridLayout *layout;
    QStackedWidget *rightWidget;
    QStandardItemModel *model;

    QStandardItem *highLightItem;
    QBrush *normalBg;
    QBrush *highLightBg;

    DBusInterfaceAdapter *interfaceAdapter;
    CircleWidget *m_circleWidget;

    MyButton *btn_quit;
signals:
    void outOfLeftItem();
public slots:
    void changeLeftWidget(QModelIndex index);
    void EnterLeftItem(QModelIndex index);
    void OuterLeftItem();
    void isCalculateCarton();
    void finishedCalcCarton();
};

#endif // MAINWINDOW_H

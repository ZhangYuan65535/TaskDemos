#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "detailwindow.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void initGUI();

private:
    QLayout *m_layout;
    QStackedWidget *m_leftWindows;
    DetailWindow *m_detailWindow;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    m_layout(new QHBoxLayout(this)),
    m_leftWindows(new QStackedWidget),
    m_detailWindow(new DetailWindow(this))
{
    initGUI();
}

void MainWindow::initGUI()
{
    m_layout->addWidget(m_leftWindows);
    m_leftWindows->addWidget(m_detailWindow);
}

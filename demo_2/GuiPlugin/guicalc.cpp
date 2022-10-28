#include "guicalc.h"
#include <QDebug>
#include <QWidget>

GuiCalc::GuiCalc(QObject *parent) :
    QObject(parent)
{
    qWarning()<<"开启图形化界面";
}

GuiCalc::~GuiCalc()
{
    delete m_mainWindow;
}

void GuiCalc::run()
{
    m_mainWindow = new MainWindow();
    m_mainWindow->show();
}

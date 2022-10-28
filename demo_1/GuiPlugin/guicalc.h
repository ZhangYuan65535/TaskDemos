#pragma once

#include "guicalcinterface.h"
#include "mainwindow.h"
#include <QObject>
#include <QWidget>

/**
 * @brief The GuiCalc class 插件实现类，用于开启图形化界面
 */
class GuiCalc : public QObject,public GuiCalcInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID GuiCalcInterface_iid)
    Q_INTERFACES(GuiCalcInterface)
public:
    explicit GuiCalc(QObject *parent = nullptr);
    ~GuiCalc();
    virtual void run();
private:
    MainWindow *m_mainWindow;
};

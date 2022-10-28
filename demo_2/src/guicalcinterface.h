#pragma once

#include <QtPlugin>
//#include <QObject>

/**
 * @brief The GuiCalcInterface class 插件接口类，规定插件应实现的功能
 */
class GuiCalcInterface
{
public:
    virtual ~GuiCalcInterface(){}
    virtual void run() = 0;
};

#define GuiCalcInterface_iid "Examples.Plugin.GuiCalcInterface"
QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(GuiCalcInterface, GuiCalcInterface_iid)
QT_END_NAMESPACE

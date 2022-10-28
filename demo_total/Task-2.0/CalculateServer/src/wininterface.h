#ifndef WININTERFACE_H
#define WININTERFACE_H

#include <QString>
#include <QtPlugin>

class WinInterface
{
public:
    virtual ~WinInterface() {}
};

#define WinInterface_iid "Examples.Plugin.WinInterface"
QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(WinInterface, WinInterface_iid)
QT_END_NAMESPACE

#endif // WININTERFACE_H

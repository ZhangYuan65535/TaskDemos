TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets dbus
INCLUDEPATH    += ../calculator
TARGET          = $$qtLibraryTarget(guiplugin)
DESTDIR         = ../plugins

HEADERS += \
    guicalc.h \
    mainwindow.h \
    roundbutton.h

SOURCES += \
    guicalc.cpp \
    mainwindow.cpp \
    roundbutton.cpp

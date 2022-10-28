#-------------------------------------------------
#
# Project created by QtCreator 2022-10-12T15:18:25
#
#-------------------------------------------------

QT       += core gui dbus


CONFIG += link_pkgconfig c++14
PKGCONFIG += gsettings-qt


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    mylistviewitem.cpp \
    mylistview.cpp \
    incwidget.cpp \
    factorialwidget.cpp \
    dbusinterfaceadapter.cpp \
    primewidget.cpp \
    circlewidget.cpp \
    mybutton.cpp \
    myqgsettings.cpp

HEADERS += \
    mainwindow.h \
    mylistviewitem.h \
    mylistview.h \
    incwidget.h \
    factorialwidget.h \
    dbusinterfaceadapter.h \
    primewidget.h \
    circlewidget.h \
    mybutton.h \
    myqgsettings.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

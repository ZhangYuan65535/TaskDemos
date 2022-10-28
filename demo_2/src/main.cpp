#include "cmdcalc.h"

#include <stdio.h>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    CmdCalc cmd;
    cmd.setApp(&app);
}

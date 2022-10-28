#pragma once
#include "guicalcinterface.h"
#include <QObject>
#include <QDebug>
#include <string>
#include <QStack>
#include <QMap>
#include <QObject>
#include <QApplication>

/**
 * @brief The CmdCalc class 管理类
 * 实现从命令行接受用户输入
 * 分析用户的指令，并执行不同的操作
 * 可以加载插件，开启图形界面
 */
class CmdCalc : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.yuan.Demo1.CmdCalc")
public:
    explicit CmdCalc(QObject *parent = nullptr);
    ~CmdCalc();
    QString getItem(QString&,int&);
    int _calculate(int,int,QChar);
    void _operatorDeal();
    void operatorDeal(QChar);
    void calculate(QString);
    bool loadPlugin();
    void linkToDBus();
    inline void setApp(QApplication *app){
        this->app = app;
    }
public slots:
    int calculateForGui(QString str);
private:
    bool m_isLooped;            //命令行模式下的循环判断条件
    QMap<QChar,int> opLevel;    //记录不用运算符的等级，用于中缀转后缀
    QStack<QChar> opStack;      //操作符栈
    QStack<int> digitStack;     //数值栈
    QApplication *app;          //加载图形界面时，用于开启事件循环
    GuiCalcInterface *guiCalcInterface; //插件相关

};


#pragma once

#include "roundbutton.h"
#include "cmdcalc.h"
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QDBusInterface>

/**
 * @brief The MainWindow class 窗口界面类
 */
class MainWindow : public QWidget
{
    Q_OBJECT
    /**
     * @brief The lastType enum 标识上次输入的数据类型
     */
    enum lastType{
        typeInit,   //上次输入记录为空
        typeNum,    //上次输入为数值
        typeOp      //上次输入为操作符
    };

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createGui();
    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void calculate();
    void receiveFromMouse(QString);
    void receiveFromKey(int);
    void insertToInput(int);
    void insertToInput(QString);

private:
    QList<RoundButton*> btn_list;   //按钮清单
    QLineEdit *lineEdit_output;     //结果栏
    QLineEdit *lineEdit_input;      //输入栏
    QGridLayout *layout;
    QDBusInterface *dbusInter;      //用于请求运算服务
    lastType m_lastType;            //上次输入数据类型
};


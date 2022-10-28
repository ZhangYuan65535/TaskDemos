#include "mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QDBusReply>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    m_lastType(typeInit)
{
    setMouseTracking(true);

    dbusInter = new QDBusInterface("com.yuan.Demo1","/com/yuan/Demo1","com.yuan.Demo1.CmdCalc",QDBusConnection::sessionBus());
    if(!dbusInter->isValid()){
        qWarning()<<QDBusConnection::sessionBus().lastError().message();
        exit(-1);
    }

    this->setFixedSize(290,460);
    this->setWindowTitle("计算器");
    layout = new QGridLayout(this);
    this->setLayout(layout);

    lineEdit_output = new QLineEdit(this);
    lineEdit_output->setFixedHeight(50);
    lineEdit_output->setEnabled(false);
    lineEdit_output->setAlignment(Qt::AlignRight);
    layout->addWidget(lineEdit_output,0,0,1,4);

    lineEdit_input = new QLineEdit(this);
    lineEdit_input->setFixedHeight(50);
    lineEdit_input->setAlignment(Qt::AlignRight);
    lineEdit_input->installEventFilter(this);
    layout->addWidget(lineEdit_input,1,0,1,4);

    layout->addWidget(new RoundButton(60,60,"AC",this),2,0,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"!",this),2,1,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"%",this),2,2,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"/",this),2,3,1,1,Qt::AlignCenter);

    layout->addWidget(new RoundButton(60,60,"7",this),3,0,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"8",this),3,1,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"9",this),3,2,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"*",this),3,3,1,1,Qt::AlignCenter);

    layout->addWidget(new RoundButton(60,60,"4",this),4,0,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"5",this),4,1,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"6",this),4,2,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"-",this),4,3,1,1,Qt::AlignCenter);

    layout->addWidget(new RoundButton(60,60,"1",this),5,0,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"2",this),5,1,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"3",this),5,2,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"+",this),5,3,1,1,Qt::AlignCenter);

    layout->addWidget(new RoundButton(130,60,"0",this),6,0,1,2,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,".",this),6,2,1,1,Qt::AlignCenter);
    layout->addWidget(new RoundButton(60,60,"=",this),6,3,1,1,Qt::AlignCenter);

    //给所有按钮安装事件过滤器
    QList<RoundButton*> btnList = this->findChildren<RoundButton*>();
    for(auto btn : btnList)
    {
        btn->installEventFilter(this);
    }

}

MainWindow::~MainWindow()
{
    delete dbusInter;
}

/**
 * @brief MainWindow::calculate 将输入栏准备好的数据交由 DBus 上的服务处理
 */
void MainWindow::calculate()
{
    QDBusReply<int> reply = dbusInter->call("calculateForGui",lineEdit_input->text());
    lineEdit_output->setText(lineEdit_input->text() + QString("=") + QString::number(reply));
    lineEdit_input->setText(QString::number(reply));
}

/**
 * @brief MainWindow::receiveFromMouse 处理鼠标按下事件
 * @param key_str 字符串，事件发送方的 objectName 属性
 */
void MainWindow::receiveFromMouse(QString key_str)
{
    bool isOk;
    int key_int = key_str.toInt(&isOk);
    if(isOk){
        insertToInput(key_str.toInt());
        m_lastType = typeNum;
    }else{
        insertToInput(key_str);
    }
}

/**
 * @brief MainWindow::receiveFromKey 处理键盘按下事件
 * @param key_int 被按下的键的 int 值
 */
void MainWindow::receiveFromKey(int key_int)
{
    if(key_int >= 48 && key_int <= 57){
        receiveFromMouse(QString::number(key_int - 48));
    }else{
        switch(key_int){
        case Qt::Key_Plus:
            insertToInput("+");
            break;
        case Qt::Key_Minus:
            insertToInput("-");
            break;
        case Qt::Key_Asterisk:
            insertToInput("*");
            break;
        case Qt::Key_Slash:
            insertToInput("/");
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            insertToInput("=");
            break;
        case Qt::Key_Escape:
            insertToInput("AC");
            break;
        }
    }
}

/**
 * @brief MainWindow::insertToInput 将数值追加到输入栏
 * @param n 要追加的数值
 */
void MainWindow::insertToInput(int n)
{
    QString oldText = lineEdit_input->text();
    lineEdit_input->setText(oldText.append(QString::number(n)));
    m_lastType = typeNum;
}

/**
 * @brief MainWindow::insertToInput 将操作符追加到输入栏
 * @param op 要追加的操作符
 */
void MainWindow::insertToInput(QString op)
{
    if(op == "AC"){                     //清屏操作
        lineEdit_input->clear();
        lineEdit_output->clear();
        m_lastType = typeInit;
    }else if(op == "="){                //求值操作
        calculate();
        m_lastType = typeNum;
    }else{                              //运算符操作
        QString oldText = lineEdit_input->text();
        QString newText;
        if(m_lastType == typeOp){
            newText = oldText.left(oldText.size() - 1).append(op);
        }else if(m_lastType == typeInit){
            return;
        }else{
            newText = oldText.append(op);
        }
        lineEdit_input->setText(newText);
        m_lastType = typeOp;
    }
}

/**
 * @brief MainWindow::eventFilter 事件过滤器，对于鼠标按下和键盘按下事件，采用不同处理方式，其它事件放行
 */
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        receiveFromMouse(watched->objectName());
    }else if(event->type() == QEvent::KeyPress){
        QKeyEvent *e = static_cast<QKeyEvent*>(event);
        receiveFromKey(e->key());
        return true;
    }else{
        return false;
    }
}



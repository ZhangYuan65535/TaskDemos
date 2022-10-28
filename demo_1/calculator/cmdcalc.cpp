#include "cmdcalc.h"
#include <string>
#include <iostream>
#include <QStack>
#include <QDir>
#include <QPluginLoader>
#include <QApplication>
#include <QDBusConnection>
#include <QDBusError>
#include <QApplication>

using std::cin;
using std::cout;
using std::endl;

CmdCalc::CmdCalc(QObject *parent):
    QObject(parent)
{
    m_isLooped = true;
    opLevel.insert('(',0);
    opLevel.insert('+',1);
    opLevel.insert('-',1);
    opLevel.insert('*',2);
    opLevel.insert('/',2);

    while(m_isLooped)
    {
        std::string tmpStr;
        cout<<"input >> ";
        std::getline(cin,tmpStr);
        // 去掉表达式中的空格
        int index = 0;
        if(!tmpStr.empty()){
            while( (index = tmpStr.find(' ',index)) != std::string::npos){
                tmpStr.erase(index,1);
            }
        }
        calculate(QString::fromStdString(tmpStr));
    }
}

CmdCalc::~CmdCalc()
{
    delete guiCalcInterface;
}

static bool _isDigit(QChar c)
{
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

static bool _isOperator(QChar c)
{
    switch(c.toLatin1())
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return true;
    }
    return false;
}

/**
 * @brief CmdCalc::getItem 从字符串指令中指定位置开始，解析出一个完整的数值或运算符
 * @param expression 字符串指令
 * @param i 起点
 * @return 将解析结果以字符串形式返回
 */
QString CmdCalc::getItem(QString &expression,int &i)
{
    QString result{};
    for( ;i < expression.size(); ){
        if(_isOperator(expression[i])){
            result.append(expression[i]);
            i++;
            break;
        }else if(_isDigit(expression[i])){
            while(_isDigit(expression[i])){
                result.append(expression[i]);
                i++;
            }
            break;
        }else{
            break;
        }
    }
    return result;
}

int CmdCalc::_calculate(int num1, int num2, QChar op)
{
    switch(op.toLatin1()){
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    default:
        exit(-1);
    }
}

/**
 * @brief CmdCalc::_operatorDeal 一次运算操作，从栈中获取两个数值和一个操作符，进行运算，并将结果压栈
 */
void CmdCalc::_operatorDeal()
{
    int num1;
    int num2;
    int ret;
    QChar op;
    num2 = digitStack.pop();
    num1 = digitStack.pop();
    op = opStack.pop();
    ret = _calculate(num1,num2,op);
    digitStack.push(ret);
}

/**
 * @brief CmdCalc::operatorDeal 对不同操作符的操作进行分流
 * @param c 接受到的操作符
 */
void CmdCalc::operatorDeal(QChar c)
{
    if(c == ')'){
        while(opStack.top() != '('){
            _operatorDeal();
        }
        opStack.pop();
        return;
    }else if(c == '('){
        opStack.push(c);
    }else{
        while(!opStack.isEmpty() && opLevel[c] <= opLevel[opStack.top()]){
            _operatorDeal();
        }
        opStack.push(c);
    }
}
/**
 * @brief CmdCalc::calculate 接收字符串指令并解析指令
 * @param expression 用户指令
 */
void CmdCalc::calculate(QString expression)
{
    if(QString::compare(expression,"quit",Qt::CaseInsensitive) == 0 || QString::compare(expression,"q",Qt::CaseInsensitive) == 0){
        m_isLooped = false;
    }else if(QString::compare(expression,"gui",Qt::CaseInsensitive) == 0){
        if(loadPlugin() == true){
            //run() 方法会实例化一个图形界面
            guiCalcInterface->run();
            //若插件加载成功，则开启事件循环
            app->exec();
        }
    }else{
        opStack.clear();
        digitStack.clear();
        for(int i = 0; i < expression.size();){
            QString item = getItem(expression,i);
            if(_isDigit((item[0]))){
                digitStack.push(item.toInt());
            }else if(_isOperator(item[0])){
                operatorDeal(item[0]);
            }else{
                qWarning()<<"输入不规范，请重新输入!";
                return;
            }
        }
        while(!opStack.isEmpty()){
            _operatorDeal();
        }
        qWarning()<<digitStack.top();
    }
    return;
}

/**
 * @brief CmdCalc::loadPlugin 加载插件，并通过 DBus 将所有槽函数公开
 * @return 返回加载结果，true 表示加载成功
 */
bool CmdCalc::loadPlugin()
{
    bool ret = true;
    QDir pluginsDir(qApp->applicationDirPath());
    pluginsDir.cdUp();
    pluginsDir.cd("plugins");
    foreach(QString fileName,pluginsDir.entryList(QDir::Files)){
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if(plugin){
            QString pluginName = plugin->metaObject()->className();
            if(pluginName == "GuiCalc"){
                guiCalcInterface = qobject_cast<GuiCalcInterface*>(plugin);
                if(guiCalcInterface){
                    ret = true;
                    linkToDBus();
                }
                break;
            }else{
                ret = false;
            }
        }
    }
    return ret;
}

/**
 * @brief CmdCalc::linkToDBus 注册 DBus 服务
 */
void CmdCalc::linkToDBus()
{
    QDBusConnection conn = QDBusConnection::sessionBus();
    if(!conn.registerService("com.yuan.Demo1")){
        qWarning()<<"error:"<<conn.lastError().message();
        exit(-1);
    }
    conn.registerObject("/com/yuan/Demo1",this,QDBusConnection::ExportAllSlots);
}

int CmdCalc::calculateForGui(QString str)
{
    calculate(str);
    return digitStack.top();
}

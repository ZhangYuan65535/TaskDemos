#ifndef MYMATH_H
#define MYMATH_H

#include <QObject>

class MyMathPrivate;
class MyMath : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(MyMath)
    enum number{
        one,
        three,
    };
public:
    explicit MyMath(QObject *parent = nullptr);
    ~MyMath();

    void setParam(int p1,int p2);
    // == 测试1: 给已有的成员函数添加新参数或修改已有参数类型,结果是破坏了二进制兼容性
//    void setParam(int p1,int p2,int p3);
    int add();

    // == 测试3： 如果只用成员函数获取数据，客户端无需用到 offset，那么当你尝试 测试2 时，是可以成功的
    double getData();
private:
    // == 测试2: 添加数据成员,结果是，在已有数据成员上方添加数据会出现段错误，
    //          在最下面添加数据成员暂时是安全的，但考虑到该类可能会被其它类继承，所以并不安全
    double d1;
    double d2;
    double d3;
    MyMathPrivate *d_ptr;
    double d4;
    double d5;
    double d6;
};

#endif // MYMATH_H

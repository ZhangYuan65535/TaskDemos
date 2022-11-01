#include "sharedtest.h"
#include <QApplication>
#include <QScopedPointer>
#include <QPointer>

/**
 * @brief test1 测试 QSharedPointer
 * 当 QSharedPointer 之间存在存在环时，将无法自动销毁，基于这个原因，引入了 QWeakPointer
 */
void test1()
{
    qWarning() << "=====test1()=====";
    QSharedPointer<SharedTest> p1(new SharedTest);
    QSharedPointer<SharedTest> p2(new SharedTest);
    p1->sp = p2;
    p2->sp = p1;
}

/**
 * @brief test2 测试 QWeakPointer
 * QWeakPointer 不能直接用来操作对象，但可以通过其 lock() 函数获取对应的 QSharedPointer，其存在的意义就是防止循环引用
 */
void test2()
{
    qWarning() << "=====test2()=====";
    QSharedPointer<WeakTest> p1(new WeakTest);
    QSharedPointer<WeakTest> p2(new WeakTest);
    p1->sp = p2;
    p2->sp = p1;
    p1->sp.lock();

    //使用 QWeakPointer 提取 QSharedPointer 后，要进行非空判断，否则可能会出现意想不到的错误
    QWeakPointer<SharedTest> p3;
    if( p3.lock().isNull() ){
        qWarning() << "QWeakPointer is Null";
    }
    QSharedPointer<SharedTest> p4 = p3.lock();
//    qWarning() << p4->str;      //这里程序会报错
}

/**
 * @brief test3 测试 QScopedPointer
 * 由于 QScopedPointer 的拷贝构造与赋值构造都是 private 的，所以很类似于 C++ 的 unique_ptr
 */
void test3()
{
    qWarning() << "=====test3()=====";
    QScopedPointer<SharedTest> p1(new SharedTest);
//    QScopedPointer<SharedTest> p2 = p1;             //尝试拷贝 QScopedPointer 将会报错
}

/**
 * @brief test4 测试 QPointer
 * 多个传统指针指向同一个对象时，对一个指针调用 delete，其它指针是无法察觉到的，在外面看来，它们依然有着明确的指向，只不过指向的是一块未知的空间
 */
void test4()
{
//    PointerTest *p1 = new PointerTest;
//    PointerTest *p2 = p1;
//    delete(p1);
//    qWarning() << (p2 == nullptr);

    PointerTest *p3 = new PointerTest;
    QPointer<PointerTest> p4(p3);
    QPointer<PointerTest> p5(p4);
    delete(p3);
    qWarning() << "p4 is null?" << p4.isNull();
    qWarning() << "p5 is null?" << p5.isNull();
}

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    test1();
    test2();
    test3();
    test4();

    return app.exec();
}

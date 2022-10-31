#include "widget.h"
#include "ui_widget.h"
#include "primetask.h"
#include "workthread.h"
#include "worker.h"
#include <QThreadPool>
#include <QDebug>
#include <QtConcurrent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::on_btn1_clicked 第一种，使用Qt原生的线程池
 * 优点：用起来方便
 * 缺点：当存在海量数据需要处理时，如果对每个数据都创建一个任务类实例，那么，
 *      光是这些任务类实例的构造就会浪费很多资源
 */
void Widget::on_btn1_clicked()
{
    QThreadPool pool;
    pool.setMaxThreadCount(8);
    for(int i = 1; i < 100; i++){
        PrimeTask *task = new PrimeTask(i);
        connect(task,SIGNAL(isPrime(int)),this,SLOT(addPrimeToEdit(int)));
        pool.start(task);
    }
    pool.waitForDone();
    qWarning() << "Finished";
}

void Widget::addPrimeToEdit(int num)
{
    QString str = ui->textEdit->toPlainText() + "  ";
    str += QString::number(num);
    ui->textEdit->setText(str);
}

/**
 * @brief Widget::on_btn2_clicked 第二种，继承 QThread类，调用 run() 方法
 * 优点：可以通过信号槽与外界通信
 * 缺点：每次新建一个线程都要写一个类，继承自QThread，线程一旦多起来，不太方便
 */
void Widget::on_btn2_clicked()
{
    WorkThread *workThread = new WorkThread(1,100);
    connect(workThread,SIGNAL(resultReady(QList<int>)),this,SLOT(addPrimeToEdit2(QList<int>)));
    workThread->start();
}

void Widget::addPrimeToEdit2(QList<int> list)
{
    QString str = ui->textEdit->toPlainText() + "  ";
    for(auto i : list){
        str += "  ";
        str += QString::number(i);
    }
    ui->textEdit->setText(str);
}

/**
 * @brief Widget::on_btn3_clicked 第三种，使用 moveToThread
 * 分析：与继承 QThread 的机制似乎差不多，区别在于，后者更加灵活，可直接将一个类的成员函数用作多线程任务。
 *      而且，对于继承 QThread，一个类只能实现一种操作，而 moveToThread 则可以实现多种操作，只需你调用
 *      不同的成员函数即可。
 */
void Widget::on_btn3_clicked()
{
    QThread workerThread;
    Worker *worker = new Worker;
    worker->moveToThread(&workerThread);
    connect(&workerThread,SIGNAL(finished()),worker,SLOT(deleteLater()));
    connect(worker,SIGNAL(resultReady(QList<int>)),this,SLOT(addPrimeToEdit2(QList<int>)));

    worker->doWork();
//    worker->doWork2();
}

static QList<int> getList()
{
    return QList<int>{1,2,3,4,5,6,7};
}

/**
 * @brief Widget::on_pushButton_clicked 第四种，使用 QtConcurrent
 * 分析：QtConcurrent 使用起来更加方便，无需新建任何类，可直接接受函数指针以开启子线程。
 *      但由于其多线程依赖于函数而不是类，所以无法享用信号槽机制，且线程结束后，不会触发信号。
 *      还有一个优势是，它会根据可用的处理器内核数，自动调整使用的线程数量，便于以后硬件的升级。
 */
void Widget::on_pushButton_clicked()
{
    QFuture<QList<int>> future = QtConcurrent::run(getList);
    future.waitForFinished();
    QList<int> list = future.result();
    addPrimeToEdit2(list);
}

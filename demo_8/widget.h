#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

/**
 * @brief The Widget class 主窗口类
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn1_clicked();
    void addPrimeToEdit(int);
    void on_btn2_clicked();
    void addPrimeToEdit2(QList<int>);
    void on_btn3_clicked();
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>

class TestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TestWidget(QWidget *parent = nullptr);

signals:

public slots:
    void test(QVariant val);
};

#endif // TESTWIDGET_H

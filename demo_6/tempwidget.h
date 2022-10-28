#ifndef TEMPWIDGET_H
#define TEMPWIDGET_H

#include <QWidget>

class TempWidget : public QWidget
{
    Q_OBJECT

public:
    TempWidget(QWidget *parent = 0);
    ~TempWidget();

    bool isHealth();
    bool isDie();
    void paintEvent(QPaintEvent *event);
public slots:
    void tempChanged(int temp);

private:
    double m_curTemp;
    QBrush *greenBrush;
    QBrush *redBrush;

};

#endif // TEMPWIDGET_H

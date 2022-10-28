#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGSettings>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGSettings *m_settings;

    int m_width;
    int m_height;
    int m_posX;
    int m_posY;
};

#endif // WIDGET_H

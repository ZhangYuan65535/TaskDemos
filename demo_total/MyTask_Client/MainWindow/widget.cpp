#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //读取 dconf 信息，确定 Widget 的大小和位置
    m_settings = new QGSettings("yuan.task.value","/yuan/task/value/");
    m_width = m_settings->get("width").toInt();
    m_height = m_settings->get("height").toInt();
    m_posX = m_settings->get("posx").toInt();
    m_posY = m_settings->get("posy").toInt();
    this->setGeometry(m_posX,m_posY,m_width,m_height);
}

Widget::~Widget()
{
    delete ui;
}

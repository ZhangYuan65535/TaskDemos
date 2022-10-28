#include "redbean.h"

RedBean::RedBean(Tea *tea):
    TeaDecorator(tea),
    price(1.5)
{

}

double RedBean::cost() const
{
    return (m_tea->cost() + price);
}

QString RedBean::getName() const
{
    return "红豆";
}

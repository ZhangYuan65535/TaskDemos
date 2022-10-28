#include "pudding.h"

Pudding::Pudding(Tea *tea):
    TeaDecorator(tea),
    price(1)
{

}

double Pudding::cost() const
{
    return (m_tea->cost() + price);
}

QString Pudding::getName() const
{
    return "布丁";
}

#include "greentea.h"

GreenTea::GreenTea():
    price(8)
{

}

double GreenTea::cost() const
{
    return price;
}

QString GreenTea::getName() const
{
    return "绿茶";
}

#include "redtea.h"

RedTea::RedTea():
    price(5)
{

}

double RedTea::cost() const
{
    return price;
}

QString RedTea::getName() const
{
    return "红茶";
}

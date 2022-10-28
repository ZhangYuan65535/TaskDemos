#pragma once

#include <QString>
#include "teadecorator.h"

class Pudding: public TeaDecorator
{
public:
    Pudding(Tea *tea);
    virtual double cost() const;
    virtual QString getName() const;
protected:
    double price;
};

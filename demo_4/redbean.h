#pragma once

#include <QString>
#include "teadecorator.h"

class RedBean: public TeaDecorator
{
public:
    RedBean(Tea *tea);
    virtual double cost() const;
    virtual QString getName() const;
protected:
    double price;
};

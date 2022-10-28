#pragma once

#include <QDebug>

class Tea
{
public:
    virtual double cost() const = 0;
    virtual QString getName() const = 0;
};

#pragma once

#include <QString>
#include "tea.h"

class RedTea: public Tea
{
public:
    RedTea();
    virtual double cost() const;
    virtual QString getName() const;
protected:
    double price;
};


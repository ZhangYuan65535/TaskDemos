#pragma once

#include <QString>
#include "tea.h"

class GreenTea: public Tea
{
public:
    GreenTea();
    virtual double cost() const;
    virtual QString getName() const;
protected:
    double price;
};


#pragma once

class BaseItem
{
public:
    virtual void show() const = 0;
    virtual bool compare(BaseItem *item1, BaseItem *item2) const = 0;
};

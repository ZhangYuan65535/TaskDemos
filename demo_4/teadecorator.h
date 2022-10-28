#pragma once

#include "tea.h"

class TeaDecorator: public Tea
{
public:
    TeaDecorator(Tea *tea):m_tea(tea){}
protected:
    Tea *m_tea;
};

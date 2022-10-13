#pragma once

#include "Figure.h"

class Rectangle :
    public Figure
{
public:

    Rectangle(const double value1, const double value2);

    void ShowArea() const;
};
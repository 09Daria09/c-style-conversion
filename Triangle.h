#pragma once

#include "Figure.h"

class Triangle :
    public Figure
{
public:

    Triangle(const double value1, const double value2);

    void ShowArea() const;
};
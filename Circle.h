#pragma once

#include "Figure.h"

class Circle : public Figure
{
public:

    Circle(const double value1);

    void ShowArea() const;
    void Test();
};
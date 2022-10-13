#include <iostream>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(const double value1, const double value2) :
    Figure(value1, value2)
{
}

void Rectangle::ShowArea() const
{
    cout << "Square of rectangle: " << m_value1 * m_value2 << endl;
}
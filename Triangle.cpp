#include <iostream>

#include "Triangle.h"

using namespace std;

Triangle::Triangle(const double value1, const double value2) :
    Figure(value1, value2)
{
}

void Triangle::ShowArea() const
{
    cout << "Square of triangle: " << 0.5 * m_value1 * m_value2 << endl;
}
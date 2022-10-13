#include <iostream>

#include "Circle.h"

using namespace std;

Circle::Circle(const double value1) :
    Figure(value1, 0.0)
{
}

void Circle::ShowArea() const
{
    cout << "Square of circle: " << 3.14159 * m_value1 * m_value2 << endl;
}

void Circle::Test()
{
    cout << "CIRCLE TEST\n";
}

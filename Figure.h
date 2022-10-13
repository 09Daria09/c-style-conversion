#pragma once

class Figure
{
protected:

    double m_value1;
    double m_value2;

public:

    Figure(const double value1, const double value2);

    virtual void ShowArea() const = 0;
};
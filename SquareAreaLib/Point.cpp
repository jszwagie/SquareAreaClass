#include "Point.h"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

int Point::distance_in_line(const Point& p) const
{
    if (getX() == p.getX())
    {
        int result = abs(getY() - p.getY());
        return result;
    }
    else if (getY() == p.getY())
    {
        int result = abs(getX() - p.getX());
        return result;
    }
    else
        throw std::invalid_argument("Points not in line");
}
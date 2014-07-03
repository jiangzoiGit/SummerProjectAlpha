#include "Point.h"

Point& Point::operator=(const Point& p)
{
    x = p.x;
    y = p.y;
    return *this;
}

bool Point::operator==(const Point& p)
{
    return (x == p.x && y == p.y);
}

bool Point::operator!=(const Point& p)
{
    return !(x == p.x && y == p.y);
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(const int _x)
{
    x = _x;
}

void Point::setY(const int _y)
{
    y = _y;
}

int Point::getIndex() const
{
    return index;
}

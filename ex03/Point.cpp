#include "Point.hpp"
#include "Fixed.hpp"

Fixed   Point::getX(void) const
{
	return (this->x);
}

Fixed   Point::getY(void) const
{
	return (this->y);
}


Point::Point(void)
	:	x(0)
	,	y(0)
{
}

Point::~Point(void)
{
}


// Point& Point::operator=(const Point& rhs)
// {
// }

Point::Point(const Point& other)
	:	x(other.x)
	,	y(other.y)
{
}

Point::Point(const float xPoint, const float yPoint)
	:	x(xPoint)
	,	y(yPoint)
{
}

Point::Point(const Fixed xPoint, const Fixed yPoint)
	:	x(xPoint.getRawBits())
	,	y(yPoint.getRawBits())
{
}
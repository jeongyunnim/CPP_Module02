#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"

class Point
{

public:

	Fixed   getX(void) const;
	Fixed   getY(void) const;

	Point(void);
	~Point(void);
	Point(const Point& other);

	Point(const Fixed xPoint, const Fixed yPoint);
	Point(const float xPoint, const float yPoint);

private:
	
	Point& operator=(const Point& rhs);
	const Fixed x;
	const Fixed y;

};

#endif
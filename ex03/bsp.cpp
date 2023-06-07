#include "Fixed.hpp"
#include "Point.hpp"
    
    
bool    bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	abVector(b.getX() - a.getX(), b.getY() - a.getY());
	Point	acVector(b.getX() - c.getX(), b.getY() - c.getY());
	Fixed	alpha;
	Fixed	beta;

	return (true);
}

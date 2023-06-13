#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
	Point	a(-1,-1);
	Point	b(1,-1);
	Point	c(0,1);
	Point	p(0.255, 0);

	bsp(a, b, c, p);
	return 0;
}
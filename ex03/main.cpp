#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
	Point	a1(-1,-1);
	Point	b1(1,-1);
	Point	c1(0,1);
	Point	p1(0.255, 0);

	std::cout << "=======================================================" << std::endl;
	std::cout << "<First Test>" << std::endl;
	if (bsp(a1, b1, c1, p1) == true)
		std::cout << "result: [True] Point is inside of the triangle\n" << std::endl;
	else
		std::cout << "result: [false] Point is outside of the triangle or edge of the triangle\n" << std::endl;

	Point	a2(-25,25);
	Point	b2(15,0);
	Point	c2(-15,0);
	Point	p2(0, 0.1);

	std::cout << "=======================================================" << std::endl;
	std::cout << "<Second Test>" << std::endl;
	if (bsp(a2, b2, c2, p2) == true)
		std::cout << "result: [True] Point is inside of the triangle\n" << std::endl;
	else
		std::cout << "result: [false] Point is outside of the triangle or edge of the triangle\n" << std::endl;

	Point	a3(-25,25);
	Point	b3(15,0);
	Point	c3(-15,0);
	Point	p3(0.74, -1.502);

	std::cout << "=======================================================" << std::endl;
	std::cout << "<Third Test>" << std::endl;
	if (bsp(a3, b3, c3, p3) == true)
		std::cout << "result: [True] Point is inside of the triangle\n" << std::endl;
	else
		std::cout << "result: [false] Point is outside of the triangle or edge of the triangle\n" << std::endl;

	return (0);
}
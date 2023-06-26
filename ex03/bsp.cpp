#include "Point.hpp"

bool    bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	denominator(((b.getY() - c.getY()) * (a.getX() - c.getX())) + ((c.getX() - b.getX()) * (a.getY() - c.getY())));
	float	denominatorF;
	Fixed	alpha;
	float	alphaF;
	Fixed	beta;
	float	betaF;

	denominatorF = ((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));
	if (denominator.getRawBits() == 0)
		return (false);
	alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
	beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
	alphaF = ((b.getY().toFloat() - c.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())) / denominator.toFloat();
	betaF = ((c.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat()) + (a.getX().toFloat() - c.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())) / denominator.toFloat();

	std::cout << "alpha: " << alpha << std::endl;
	std::cout << "beta: " << beta << std::endl;
	std::cout << "\n<float>" << std::endl;
	std::cout << "alphaF: " << alphaF << std::endl;
	std::cout << "betaF: " << betaF << std::endl;
	std::cout << "=======================================================" << std::endl;
	if (alpha <= 0 || alpha >= 1 || beta <= 0 || beta >= 1 || alpha + beta >= 1)
		return (false);
	return (true);
}

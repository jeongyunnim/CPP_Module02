#include "Point.hpp"
    
bool    bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	abVector(b.getX() - a.getX(), b.getY() - a.getY());
	Point	acVector(c.getX() - a.getX(), c.getY() - a.getY());
	Fixed	alpha;
	Fixed	beta;

	float	ab[2];
	float	ac[2];
	float	alphaF;
	float	betaF;

	ab[0] = (b.getX() - a.getX()).toFloat();
	ab[1] = (b.getY() - a.getY()).toFloat();
	ac[0] = (c.getX() - a.getX()).toFloat();
	ac[1] = (c.getY() - a.getY()).toFloat();
	alphaF = ((ac[1] * point.getX().toFloat()) - (ac[0] * point.getY().toFloat())) / ((ab[0] * ac[1]) - (ab[1] * ac[0]));
	betaF = ((ab[0] * point.getY().toFloat()) - (ab[1] * point.getX().toFloat())) / ((ab[0] * ac[1]) - (ab[1] * ac[0]));
	if ((ab[0] * ac[1]) - (ab[1] * ac[0]) == 0)
		return (false);
	std::cout << "abVector: (" << abVector.getX() << ", " << abVector.getY() << ')' << std::endl;
	std::cout << "acVector: (" << acVector.getX() << ", " << acVector.getY() << ")\n\n" << std::endl;
	alpha = ((acVector.getY() * point.getX()) - (acVector.getX() * point.getY())) / ((abVector.getX() * acVector.getY()) - (abVector.getY() * acVector.getX()));
	beta = ((abVector.getX() * point.getY()) - (abVector.getY() * point.getX())) / ((abVector.getX() * acVector.getY()) - (abVector.getY() * acVector.getX()));
	if ((abVector.getX() * acVector.getY()) - (abVector.getY() * acVector.getX()) == 0)
	{
		std::cout << "fractional is zero" << std::endl;
		return (false);
	}
	alpha = ((acVector.getY() * point.getX()) - (acVector.getX() * point.getY())) / ((abVector.getX() * acVector.getY()) - (abVector.getY() * acVector.getX()));
	beta = ((abVector.getX() * point.getY()) - (abVector.getY() * point.getX())) / ((abVector.getX() * acVector.getY()) - (abVector.getY() * acVector.getX()));

	std::cout << "alpha: " << alpha << std::endl;
	std::cout << "beta: " << beta << std::endl;
	std::cout << "alphaF: " << alphaF << std::endl;
	std::cout << "betaF: " << betaF << std::endl;
	if (alpha <= 0 || alpha >= 1 || beta <= 0 || beta >= 1 || alpha + beta >= 1)
		return (false);
	return (true);
}

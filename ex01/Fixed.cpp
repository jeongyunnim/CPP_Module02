#include <cstring>
#include "Fixed.hpp"

const int Fixed::fractional = 8;

int	Fixed::getRawBits(void) const
{
	return (rawBit);
}

void	Fixed::setRawBits(const int raw)
{
	rawBit = raw;
}

Fixed::Fixed()
	:	rawBit(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(f.getRawBits());
}

Fixed::Fixed(const int value)
{
	rawBit = value << fractional;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	setRawBits(roundf(value * (1 << fractional)));
}

int	Fixed::toInt(void) const
{
	int	result;

	result = roundf(toFloat());
	return (result);
}

float	Fixed::toFloat(void) const
{
	float	result;
	
	result = getRawBits() / static_cast<float>(1 << fractional);
	return (result);
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return (out);
}

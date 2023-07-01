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
	rawBit = f.rawBit;
	return (*this);
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
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
	float	fractionalPart;
	int		intPart;
	int		signPart;

	if (rawBit < 0)
	{
		signPart = -1;
		intPart = static_cast<int>((rawBit * signPart) >> fractional);
		fractionalPart = 1 - (static_cast<float>(rawBit & 0xFF) / (1 << fractional));
	}
	else
	{
		signPart = 1;
		intPart = static_cast<int>(rawBit >> fractional);
		fractionalPart = (static_cast<float>(rawBit & 0xFF) / (1 << fractional));
	}
	result = (intPart + fractionalPart) * signPart;
	return (result);
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return (out);
}

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
	int		intPart;
	int		fractionalPart;
	int		signPart;

	if (value < 0)
		signPart = -1;
	else
		signPart = 1;
	intPart = static_cast<int>(std::abs(value));
	fractionalPart = static_cast<int>((std::abs(value) - intPart) * (1 << fractional));
	setRawBits((intPart << fractional | fractionalPart) * signPart);
}

int	Fixed::toInt(void) const
{
	int	result;

	result = round(toFloat());
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

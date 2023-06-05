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
	:	rawBit(value << fractional)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	float	result;
	std::cout << "Float constructor called" << std::endl;
	result = value * pow(2, 8);
	setRawBits(result);
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> fractional);
}

float	Fixed::toFloat(void) const
{
	float	result;
	int		integer;
	int		decimal;

	integer = getRawBits() >> 8;
	decimal = getRawBits() - integer;
	result = integer + static_cast<float>(decimal * pow(2, -8));
	return (result);
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	int	integer;
	int	decimal;

	integer = rhs.getRawBits() >> 8;
	decimal = rhs.getRawBits() - integer;
	if (decimal != 0)
		out << integer << '.' << decimal;
	else
		out << integer;
	return (out);
}

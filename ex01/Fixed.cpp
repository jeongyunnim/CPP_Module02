#include "Fixed.hpp"

const int Fixed::fractional = 8;

int	Fixed::getRawBits(void) const
{
	int	result;
	std::cout << "getRawBits member function called" << std::endl;
	result = rawBit >> fractional;
	return (result);
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
	setRawBits(f.getRawBits());
	return (*this);
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int value)
	:	rawBit(value << fractional)
{
}

Fixed::Fixed(const float value)
{
	setRawBits(value * pow(2, fractional));
}

Fixed& Fixed::operator<<(const Fixed& f)
{
	std::cout << f.rawBit;
	return *this;
}


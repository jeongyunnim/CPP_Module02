#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	temp;

	if (lhs.getRawBits() > rhs.getRawBits())
		temp.rawBit = lhs.getRawBits();
	else
		temp.rawBit = rhs.getRawBits();
	return (temp);
}

Fixed	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	Fixed	temp;

	if (lhs.getRawBits() > rhs.getRawBits())
		temp.rawBit = lhs.getRawBits();
	else
		temp.rawBit = rhs.getRawBits();
	return (temp);
}

Fixed	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	temp;

	if (lhs.getRawBits() < rhs.getRawBits())
		temp.rawBit = lhs.getRawBits();
	else
		temp.rawBit = rhs.getRawBits();
	return (temp);
}

Fixed	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	Fixed	temp;

	if (lhs.getRawBits() < rhs.getRawBits())
		temp.rawBit = lhs.getRawBits();
	else
		temp.rawBit = rhs.getRawBits();
	return (temp);
}


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
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& f)
{
	this->setRawBits(f.getRawBits());
	return (*this);
}

Fixed::Fixed(const Fixed& f)
{
	setRawBits(f.getRawBits());
}

Fixed::Fixed(const int value)
{
	rawBit = value << fractional;
}

Fixed::Fixed(const float value)
{
	setRawBits(roundf(value * (1 << fractional)));
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

bool		Fixed::operator>(const Fixed& rhs)
{
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator<(const Fixed& rhs)
{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator>=(const Fixed& rhs)
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator<=(const Fixed& rhs)
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator==(const Fixed& rhs)
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool		Fixed::operator!=(const Fixed& rhs)
{
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	else
		return (false);
}

Fixed		Fixed::operator+(const Fixed& rhs)
{
	Fixed	temp;
	
	temp.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (temp);
}

Fixed		Fixed::operator-(const Fixed& rhs)
{
	Fixed	temp;
	
	temp.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (temp);
}

Fixed		Fixed::operator*(const Fixed& rhs)
{
	float	result;
	
	result = (this->getRawBits() * rhs.getRawBits()) / (1 << fractional);
	Fixed	temp(result / (1 << fractional));
	
	return (temp);
}

Fixed		Fixed::operator/(const Fixed& rhs)
{
	float	result;
	Fixed	temp;
	
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "Error\nDived by zero error" << std::endl;
		temp.setRawBits(0);
		return (temp);
	}
	result = ((this->getRawBits() * (1 << fractional))) / rhs.getRawBits();
	temp.setRawBits(result);
	return (temp);
}

Fixed&		Fixed::operator++(void)
{
	this->rawBit += 1;
	return (*this);
}

Fixed&		Fixed::operator--(void)
{
	this->rawBit -= 1;
	return (*this);
}

const Fixed	Fixed::operator++(int _val)
{
	Fixed	temp;

	(void) _val;
	temp = *this;
	this->rawBit += 1;
	return (temp);
}

const Fixed	Fixed::operator--(int _val)
{
	Fixed	temp;

	(void) _val;
	temp = *this;
	this->rawBit -= 1;
	return (temp);
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return (out);
}
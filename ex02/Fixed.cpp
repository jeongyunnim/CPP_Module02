#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	temp;

	if (lhs.rawBit > rhs.rawBit)
		temp.rawBit = lhs.rawBit;
	else
		temp.rawBit = rhs.rawBit;
	return (temp);
}

Fixed	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	Fixed	temp;

	if (lhs.rawBit > rhs.rawBit)
		temp.rawBit = lhs.rawBit;
	else
		temp.rawBit = rhs.rawBit;
	return (temp);
}

Fixed	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	temp;

	if (lhs.rawBit < rhs.rawBit)
		temp.rawBit = lhs.rawBit;
	else
		temp.rawBit = rhs.rawBit;
	return (temp);
}

Fixed	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	Fixed	temp;

	if (lhs.rawBit < rhs.rawBit)
		temp.rawBit = lhs.rawBit;
	else
		temp.rawBit = rhs.rawBit;
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
	this->rawBit = f.rawBit;
	return (*this);
}

Fixed::Fixed(const Fixed& f)
{
	rawBit = f.rawBit;
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

	result = rawBit / static_cast<float>(1 << fractional);
	return (result);
}

bool		Fixed::operator>(const Fixed& rhs)
{
	if (this->rawBit > rhs.rawBit)
		return (true);
	else
		return (false);
}

bool		Fixed::operator<(const Fixed& rhs)
{
	if (this->rawBit < rhs.rawBit)
		return (true);
	else
		return (false);
}

bool		Fixed::operator>=(const Fixed& rhs)
{
	if (this->rawBit >= rhs.rawBit)
		return (true);
	else
		return (false);
}

bool		Fixed::operator<=(const Fixed& rhs)
{
	if (this->rawBit <= rhs.rawBit)
		return (true);
	else
		return (false);
}

bool		Fixed::operator==(const Fixed& rhs)
{
	if (this->rawBit == rhs.rawBit)
		return (true);
	else
		return (false);
}

bool		Fixed::operator!=(const Fixed& rhs)
{
	if (this->rawBit != rhs.rawBit)
		return (true);
	else
		return (false);
}

Fixed		Fixed::operator+(const Fixed& rhs)
{
	Fixed	temp;
	
	temp.rawBit = this->rawBit + rhs.rawBit;
	return (temp);
}

Fixed		Fixed::operator-(const Fixed& rhs)
{
	Fixed	temp;
	
	temp.rawBit = rawBit - rhs.rawBit;
	return (temp);
}

Fixed		Fixed::operator*(const Fixed& rhs)
{
	float	result;
	
	result = (this->rawBit * rhs.rawBit) / (1 << fractional);
	Fixed	temp(result / (1 << fractional));
	
	return (temp);
}

Fixed		Fixed::operator/(const Fixed& rhs)
{
	float	result;
	Fixed	temp;
	
	if (rhs.rawBit == 0)
	{
		std::cerr << "Error\nDived by zero error" << std::endl;
		temp.rawBit = 0;
		return (temp);
	}
	result = ((this->rawBit * (1 << fractional))) / rhs.rawBit;
	temp.rawBit = result;
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
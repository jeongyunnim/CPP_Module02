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
	Fixed	temp(this->getRawBits() + rhs.getRawBits());

	return (temp); // 지역 변수를 반환하면 값이 어떻게 대입이 되는가? 얕은 복사가 일어나는가 깊은 복사가 일어나는가?
}

Fixed		Fixed::operator-(const Fixed& rhs)
{
	Fixed	temp(this->getRawBits() - rhs.getRawBits());

	return (temp);
}

Fixed		Fixed::operator*(const Fixed& rhs)
{
	float	result;
	
	// result = (this->toFloat() * rhs.toFloat());
	result = (this->getRawBits() * rhs.getRawBits()) / (1 << fractional);
	Fixed	temp(result / (1 << fractional));
	
	return (temp);
}

Fixed		Fixed::operator/(const Fixed& rhs)
{
	float	result;
	
	result = ((this->getRawBits() * (1 << fractional))) / rhs.getRawBits();
	Fixed	temp(result);
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
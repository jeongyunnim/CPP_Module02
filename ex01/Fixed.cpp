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
	/*
	1. 문자로 저장하여 변환하기
	2. 소수점 자릿수가 없을 떄까지 10을 곱하기
	3. 2진수로 생각해보기. value의 값에 2-e31을...
	4. int로 캐스팅 한 뒤 << 8을 하고 소숫점은 그 다음에 생각하기
	*/
}
Fixed& Fixed::operator<<(const Fixed& f)
{

}


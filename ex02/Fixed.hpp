#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <iomanip>

class Fixed
{

public:

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& f);
	Fixed& operator=(const Fixed& rhs);

	Fixed(const int value);
	Fixed(const float value);

	bool		operator>(const Fixed& rhs);
	bool		operator<(const Fixed& rhs);
	bool		operator>=(const Fixed& rhs);
	bool		operator<=(const Fixed& rhs);
	bool		operator==(const Fixed& rhs);
	bool		operator!=(const Fixed& rhs);
	Fixed		operator+(const Fixed& rhs);
	Fixed		operator-(const Fixed& rhs);
	Fixed		operator*(const Fixed& rhs);
	Fixed		operator/(const Fixed& rhs);
	Fixed&		operator++(void);
	Fixed&		operator--(void);
	const Fixed	operator++(int _val);
	const Fixed	operator--(int _val);

	int		toInt(void) const;
	float	toFloat(void) const;

	static Fixed	max(const Fixed& lhs, const Fixed& rhs);
	static Fixed	max(Fixed& lhs, Fixed& rhs);
	static Fixed	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed	min(Fixed& lhs, Fixed& rhs);

private:

	static const int	fractional;
	int					rawBit;

};

std::ostream& operator<<(std::ostream& out, const Fixed& rhs);

#endif

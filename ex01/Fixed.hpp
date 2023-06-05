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
	Fixed& operator=(const Fixed& f);

	Fixed(const int value);
	Fixed(const float value);
	Fixed& operator<<(const Fixed& f);

private:

	static const int	fractional;
	int					rawBit;

};

#endif

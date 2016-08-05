/*
 * complex.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include "complex.h"

complex complex::operator+(complex z)
{
	return complex(re + z.re, im + z.im);
}

complex complex::operator*(complex z)
{
	double r, i;
	r = re * z.re - im * z.im;
	i = re * z.im + im * z.re;
	return complex{r, i};
}

std::ostream& operator<<(std::ostream& os, complex z)
{
	os << "(" << z.re << ", " << z.im << ")";
	return os;
}

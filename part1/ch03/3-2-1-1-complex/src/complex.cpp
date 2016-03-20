/*
 * complex.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include "complex.h"

complex& complex::operator*=(complex z)
{
	double r, i ;
	r = re * z.re - im * z.im;
	i = re * z.im + im * z.re;
	re = r; im = i;
	return *this;
}

complex& complex::operator/=(complex z)
{
	double square = z.re*z.re + z.im*z.im;
	re /= square;
	im /= square;
	*this *= complex{z.re, -z.im};
	return *this;
}


/*
 * complex.h
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <ostream>

class complex {
	double re, im;
public:
	complex(double r=0, double i=0) : re{r}, im{i} { }
	double real() const { return re; }
	double imag() const { return im; }

	complex& operator+=(complex a)
	{
		re += a.re;
		im += a.im;
		return *this;
	}

	complex& operator+=(double a)
	{
		re += a;
		return *this;
	}
};


inline complex operator+(complex a, complex b)
{
	return a += b;
}

inline complex operator+(complex a, double b)
{
	return a += b;
}

inline complex operator+(double a, complex b)
{
	return {a+b.real(), b.imag()};
}

std::ostream& operator<<(std::ostream& os, complex a);

#endif /* COMPLEX_H_ */

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
	complex& operator+=(complex a);

	friend std::ostream& operator<<(std::ostream& os, complex a);
};

inline complex& complex::operator +=(complex a)
{
	re += a.re;
	im += a.im;
	return *this;
}

inline complex operator+(complex a, complex b)
{
	return a += b;
}


#endif /* COMPLEX_H_ */

/*
 * complex.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include "complex.h"
#include <ostream>
using std::ostream;

ostream& operator<<(ostream& os, complex a)
{
	os << "(" << a.real() << ", " << a.imag() << ")";
	return os;
}


// 18.3.3.1
#include <complex>
complex sqrt(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	std::complex<double> ans = sqrt(z);

	return {ans.real(), ans.imag()};
}

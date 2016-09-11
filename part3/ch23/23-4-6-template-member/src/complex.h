/*
 * complex.h
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <ostream>

template<typename Scalar>
class complex {
	Scalar re, im;
public:
	complex() :re{}, im{} { }
	template<typename T>
		complex(T rr, T ii =0) :re{rr}, im{ii} { }

	complex(const complex&) = default;
	template<typename T>
		complex(const complex<T>& c) : re{c.real()}, im{c.imag()} { }

	Scalar real() const { return re; }
	Scalar imag() const { return im; }
};

template<typename Scalar>
std::ostream& operator<<(std::ostream& os, complex<Scalar>& c)
{
	os << '(' << c.real() << ", " << c.imag() << ')';
	return os;
}
#endif /* COMPLEX_H_ */

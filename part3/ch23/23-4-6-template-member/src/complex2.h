/*
 * complex2.h
 *
 *  Created on: 2017/05/13
 *      Author: sasaki
 */

#ifndef COMPLEX2_H_
#define COMPLEX2_H_


#include <ostream>

template<typename Scalar>
class complex2 {
	Scalar re, im;
public:
	complex2() :re{}, im{} { }
	template<typename T>
		complex2(T rr, T ii =0) :re(rr), im(ii) { }

	complex2(const complex2&) = default;
	template<typename T>
		complex2(const complex2<T>& c) : re(c.real()), im(c.imag()) { }

	Scalar real() const { return re; }
	Scalar imag() const { return im; }
};

template<typename Scalar>
std::ostream& operator<<(std::ostream& os, complex2<Scalar>& c)
{
	os << '(' << c.real() << ", " << c.imag() << ')';
	return os;
}


#endif /* COMPLEX2_H_ */

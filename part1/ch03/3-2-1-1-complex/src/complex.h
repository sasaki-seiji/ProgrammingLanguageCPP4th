/*
 * complex.h
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

class complex {
	double re, im;
public:
	complex(double r, double i) :re{r}, im{i} {}
	complex(double r) :re{r}, im{0} {}
	complex() :re{0}, im{0} {}
	double real() const { return re; }
	void real(double d) { re = d ; }
	double imag() const { return im; }
	void imag(double d) { im = d ; }
	complex& operator+=(complex z)
		{ re += z.re; im += z.im; return *this; }
	complex& operator-=(complex z)
		{ re -= z.re; im -= z.im; return *this; }
	complex& operator*=(complex z);
	complex& operator/=(complex z);
};

inline complex operator+(complex a, complex b) { return a += b; }
inline complex operator-(complex a, complex b) { return a -= b; }
inline complex operator-(complex a) { return { -a.real(), -a.imag() }; }
	// unary minus
inline complex operator*(complex a, complex b) { return a *= b; }
inline complex operator/(complex a, complex b) { return a /= b; }

inline bool operator==(complex a, complex b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}

inline bool operator!=(complex a, complex b)
{
	return !(a == b);
};

complex sqrt(complex);
#endif /* COMPLEX_H_ */

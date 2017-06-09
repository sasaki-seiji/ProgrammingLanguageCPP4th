/*
 * complex.h
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

template<typename T>
class Complex {
	T	r, i;
public:
	Complex(const T& re = T{}, const T& im = T{}) :r{re}, i{im} { };
	Complex(const Complex&) = default;
	template<typename X>
		Complex(const Complex<X>&);

	Complex& operator=(const Complex&) = default;
	Complex& operator=(const T& o) { r = o; i = T{}; return *this; }
	Complex& operator+=(const T& o) { r += o; return *this; }

	// ...
	template<typename X>
		Complex& operator=(const Complex<X>&);
	template<typename X >
		Complex& operator+=(const Complex<X>&);
	// ...

	constexpr T real() const { return r; }
	constexpr T imag() const { return i; }
};


template<>
class Complex<float> {
	float	r, i;
public:
	constexpr Complex(float re = 0, float im = 0) :r{re},i{im} { }
	constexpr Complex(const Complex&) = default;
	explicit constexpr Complex(const Complex<double>& o);
	explicit constexpr Complex(const Complex<long double>&);
	template<typename X>
		Complex(const Complex<X>&);

	Complex& operator=(const Complex&) = default;
	Complex& operator=(float o) { r = o; i = 0; return *this; }
	Complex& operator+=(float o) { r += o; return *this; }
	// ...
	template<typename X>
		Complex& operator=(const Complex<X>&);
	template<typename X>
		Complex& operator+=(const Complex<X>&);
	// ...

	constexpr float real() const { return r; }
	constexpr float imag() const { return i; }
};

template<>
class Complex<double> {
	double	r, i;
public:
	constexpr Complex(double re = 0, double im = 0) :r{re},i{im} { }
	constexpr Complex(const Complex&) = default;
	constexpr Complex(const Complex<float>& o)
		:r{o.real()}, i{o.imag()} { }
	explicit constexpr Complex(const Complex<long double>&);
	template<typename X>
		Complex(const Complex<X>&);

	Complex& operator=(const Complex& o) = default;
	Complex& operator=(double o) { r = o; i = 0; return *this; }
	Complex& operator+=(double o) 	{ r += o; return *this; }

	// ...
	template<typename X>
		Complex& operator=(const Complex<X>&);
	template<typename X>
		Complex& operator+=(const Complex<X>&);
	// ...

	constexpr double real() const { return r; }
	constexpr double imag() const { return i; }
};


// impl for Complex<float>

constexpr Complex<float>::Complex(const Complex<double>& o)
	:r{o.real()}, i{o.imag()} { }

template<typename X>
Complex<float>& Complex<float>::operator=(const Complex<X>& o)
{
	r = o.real();
	i = o.imag();
	return *this;
}

template<typename X>
Complex<float>& Complex<float>::operator+=(const Complex<X>& o)
{
	r += o.real();
	i += o.imag();
	return *this;
}

// impl for Complex<double>

template<typename X>
Complex<double>& Complex<double>::operator=(const Complex<X>& s)
{
	r = s.real();
	i = s.imag();
	return *this;
}

template<typename X>
Complex<double>& Complex<double>::operator+=(const Complex<X>& s)
{
	r += s.real();
	i += s.imag();
	return *this;
}

// impl for Complex<X>

template<typename T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& z)
{
	os << '(' << z.real() << ',' << z.imag() << ')';
	return os;
}

template<typename T>
template<typename X>
Complex<T>::Complex(const Complex<X>& s)
	:r{s.real()},i{s.imag()}
{
}


template<typename T>
template<typename X>
Complex<T>& Complex<T>::operator=(const Complex<X>& s)
{
	r = s.real();
	i = s.imag();
	return *this;
}

template<typename T>
template<typename X>
Complex<T>& Complex<T>::operator+=(const Complex<X>& s)
{
	r += s.real();
	i += s.imag();
	return *this;
}




#endif /* COMPLEX_H_ */

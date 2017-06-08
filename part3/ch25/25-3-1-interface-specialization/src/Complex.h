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

	Complex& operator=(const Complex&);
	Complex& operator=(const T&);
	Complex& operator+=(const T&);
	// ...
	template<typename X>
		Complex& operator=(const Complex<X>&);
	template<typename X >
		Complex& operator+=(const Complex<X>&);
	// ...

	T real() const { return r; }
	T imag() const { return i; }
};


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
	std::cout << "complex<T>::complex(const complex<X>&)\n";
}

template<typename T>
Complex<T>& Complex<T>::operator=(const Complex& s)
{
	std::cout << "complex<T>::operator=(const complex&)\n";
	r = s.r;
	i = s.i;
	return *this;
}

template<typename T>
Complex<T>& Complex<T>::operator=(const T& x)
{
	std::cout << "complex<T>::operator=(const T&)\n";
	r = x;
	i = T{};
	return *this;
}

template<typename T>
Complex<T>& Complex<T>::operator+=(const T& x)
{
	std::cout << "complex<T>::operator+=(const T&)\n";
	r += x;
	return *this;
}

template<typename T>
template<typename X>
Complex<T>& Complex<T>::operator=(const Complex<X>& s)
{
	std::cout << "complex<T>::operator=(const complex<X>&)\n";
	r = s.real();
	i = s.imag();
	return *this;
}

template<typename T>
template<typename X>
Complex<T>& Complex<T>::operator+=(const Complex<X>& s)
{
	std::cout << "complex<T>::operator+=(const complex<X>&)\n";
	r += s.real();
	i += s.imag();
	return *this;
}

template<>
class Complex<float> {
	float	r, i;
public:
	constexpr Complex(float re = 0, float im = 0) :r{re},i{im} { }
	constexpr Complex(const Complex&) = default;
	template<typename X>
		Complex(const Complex<X>&);

	Complex& operator=(const Complex&);
	Complex& operator=(float);
	Complex& operator+=(float);
	// ...
	template<typename X>
		Complex& operator=(const Complex<X>&);
	template<typename X>
		Complex& operator+=(const Complex<X>&);
	// ...

	constexpr float real() const { return r; }
	constexpr float imag() const { return i; }
};

Complex<float>& Complex<float>::operator=(const Complex& s)
{
	std::cout << "complex<float>::operator=(const complex&)\n";
	r = s.r;
	i = s.i;
	return *this;
}

Complex<float>& Complex<float>::operator=(float x)
{
	std::cout << "complex<float>::operator=(float)\n";
	r = x;
	i = 0;
	return *this;
}

Complex<float>& Complex<float>::operator+=(float x)
{
	std::cout << "complex<float>::operator+=(float)\n";
	r += x;
	return *this;
}

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

	Complex& operator=(const Complex&);
	Complex& operator=(double);
	Complex& operator+=(double);
	// ...
	template<typename X>
		Complex& operator=(const Complex<X>&);
	template<typename X>
		Complex& operator+=(const Complex<X>&);
	// ...

	constexpr double real() const { return r; }
	constexpr double imag() const { return i; }
};

Complex<double>& Complex<double>::operator=(const Complex& s)
{
	std::cout << "complex<double>::operator=(const complex&)\n";
	r = s.r;
	i = s.i;
	return *this;
}

Complex<double>& Complex<double>::operator=(double x)
{
	std::cout << "complex<double>::operator=(double)\n";
	r = x;
	i = 0;
	return *this;
}

Complex<double>& Complex<double>::operator+=(double x)
{
	std::cout << "complex<doube>::operator+=(double)\n";
	r += x;
	return *this;
}

template<typename X>
Complex<double>& Complex<double>::operator=(const Complex<X>& s)
{
	std::cout << "complex<doube>::operator=(const complex<X>&)\n";
	r = s.real();
	i = s.imag();
	return *this;
}

template<typename X>
Complex<double>& Complex<double>::operator+=(const Complex<X>& s)
{
	std::cout << "complex<doube>::operator+=(const complex<X>&)\n";
	r += s.real();
	i += s.imag();
	return *this;
}

#endif /* COMPLEX_H_ */

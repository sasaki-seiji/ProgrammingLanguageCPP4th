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
class complex {
	T	r, i;
public:
	complex(const T& re = T{}, const T& im = T{});
	complex(const complex&);
	template<typename X>
		complex(const complex<X>&);
	complex& operator=(const complex&);
	complex& operator=(const T&);
	complex& operator+=(const T&);
	// ...
	template<typename X>
		complex& operator=(const complex<X>&);
	template<typename X>
		complex& operator+=(const complex<X>&);
	// ...

	T real() const { return r; }
	T imag() const { return i; }
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const complex<T>& z)
{
	os << '(' << z.real() << ',' << z.imag() << ')';
	return os;
}

template<typename T>
complex<T>::complex(const T& re, const T& im)
	:r{re},i{im}
{
	std::cout << "complex<T>::complex(const T&, const T&)\n";
}

template<typename T>
complex<T>::complex(const complex& s)
	:r{s.r},i{s.i}
{
	std::cout << "complex<T>::complex(const complex&)\n";
}

template<typename T>
template<typename X>
complex<T>::complex(const complex<X>& s)
	:r{s.r},i{s.i}
{
	std::cout << "complex<T>::complex(const complex<X>&)\n";
}

template<typename T>
complex<T>& complex<T>::operator=(const complex& s)
{
	std::cout << "complex<T>::operator=(const complex&)\n";
	r = s.r;
	i = s.i;
	return *this;
}

template<typename T>
complex<T>& complex<T>::operator=(const T& x)
{
	std::cout << "complex<T>::operator=(const T&)\n";
	r = x;
	return *this;
}

template<typename T>
complex<T>& complex<T>::operator+=(const T& x)
{
	std::cout << "complex<T>::operator+=(const T&)\n";
	r += x;
	return *this;
}

template<typename T>
template<typename X>
complex<T>& complex<T>::operator=(const complex<X>& s)
{
	std::cout << "complex<T>::operator=(const complex<X>&)\n";
	r = s.real();
	i = s.imag();
	return *this;
}

template<typename T>
template<typename X>
complex<T>& complex<T>::operator+=(const complex<X>& s)
{
	std::cout << "complex<T>::operator+=(const complex<X>&)\n";
	r += s.real();
	i += s.imag();
	return *this;
}

template<>
class complex<float> {
	float	r, i;
public:
	complex(float re = 0, float im = 0);
	complex(const complex&);
	template<typename X>
		complex(const complex<X>&);
	complex& operator=(const complex&);
	complex& operator=(float);
	complex& operator+=(float);
	// ...
	template<typename X>
		complex& operator=(const complex<X>&);
	template<typename X>
		complex& operator+=(const complex<X>&);
	// ...

	float real() const { return r; }
	float imag() const { return i; }
};

complex<float>::complex(float re, float im)
	:r{re},i{im}
{
	std::cout << "complex<float>::complex(float, float)\n";
}

complex<float>::complex(const complex& s)
	:r{s.r},i{s.i}
{
	std::cout << "complex<float>::complex(const complex&)\n";
}

complex<float>& complex<float>::operator=(const complex& s)
{
	std::cout << "complex<float>::operator=(const complex&)\n";
	r = s.r;
	i = s.i;
	return *this;
}

complex<float>& complex<float>::operator=(float x)
{
	std::cout << "complex<float>::operator=(float)\n";
	r = x;
	return *this;
}

complex<float>& complex<float>::operator+=(float x)
{
	std::cout << "complex<float>::operator+=(float)\n";
	r += x;
	return *this;
}

template<>
class complex<double> {
	double	r, i;
public:
	complex(double re = 0, double im = 0);
	complex(const complex&);
	complex(const complex<float>&);
	explicit complex(const complex<long double>&);
	template<typename X>
		complex(const complex<X>&);

	complex& operator=(const complex&);
	complex& operator=(double);
	complex& operator+=(double);
	// ...
	template<typename X>
		complex& operator=(const complex<X>&);
	template<typename X>
		complex& operator+=(const complex<X>&);
	// ...

	double real() const { return r; }
	double imag() const { return i; }
};

complex<double>::complex(double re, double im)
	:r{re},i{im}
{
	std::cout << "complex<double>::complex(double, double)\n";
}

complex<double>::complex(const complex& s)
	:r{s.r},i{s.i}
{
	std::cout << "complex<double>::complex(const complex&)\n";
}

complex<double>& complex<double>::operator=(const complex& s)
{
	std::cout << "complex<double>::operator=(const complex&)\n";
	r = s.r;
	i = s.i;
	return *this;
}

complex<double>& complex<double>::operator=(double x)
{
	std::cout << "complex<double>::operator=(double)\n";
	r = x;
	return *this;
}

complex<double>& complex<double>::operator+=(double x)
{
	std::cout << "complex<doube>::operator+=(double)\n";
	r += x;
	return *this;
}

template<typename X>
complex<double>& complex<double>::operator=(const complex<X>& s)
{
	std::cout << "complex<doube>::operator=(const complex<X>&)\n";
	r = s.real();
	i = s.imag();
	return *this;
}

template<typename X>
complex<double>& complex<double>::operator+=(const complex<X>& s)
{
	std::cout << "complex<doube>::operator+=(const complex<X>&)\n";
	r += s.real();
	i += s.imag();
	return *this;
}

#endif /* COMPLEX_H_ */

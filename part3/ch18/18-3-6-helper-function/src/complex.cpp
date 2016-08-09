/*
 * complex.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include "complex.h"
#include <ostream>
#include <istream>
#include <stdexcept>
using std::ostream;
using std::istream;
using std::runtime_error;

// *=
complex& complex::operator*=(complex a)
{
	double r = re*a.re - im*a.im;
	double i = re*a.im + im*a.re;
	re = r;
	im = i;
	return *this;
}

complex& complex::operator*=(double a)
{
	re *= a;
	im *= a;
	return *this;
}

// /=

complex& complex::operator/=(complex a)
{
	double div = a.re*a.re + a.im*a.im;
	if (div == 0) throw std::runtime_error("divid by 0 : operator /=");

	double r = (re*a.re + im*a.im) / div;
	double i = (-re*a.im + im*a.re) / div;
	re = r;
	im = i;
	return *this;
}

complex& complex::operator/=(double a)
{
	if (a == 0) throw std::runtime_error("divid by 0 : operator /=");

	re /= a;
	im /= a;
	return *this;
}


// <<, >>

ostream& operator<<(ostream& os, complex a)
{
	os << "(" << a.real() << ", " << a.imag() << ")";
	return os;
}

istream& operator>>(istream& is, complex& a)
{
	double r, i;
	char c;

	is >> c;
	if (c != '(') throw runtime_error("'(' expected : operator>>");

	is >> r;

	is >> c;
	if (c != ',') throw runtime_error("',' expected : operator>>");

	is >> i;

	is >> c;
	if (c != ')') throw runtime_error("')' expected : operator>>");

	a = {r,i};

	return is;
}

// 18.3.3.1

#include <complex>

complex sqrt(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	std::complex<double> ans = sqrt(z);

	return {ans.real(), ans.imag()};
}

complex polar(double rho, double theta)
{
	std::complex<double> z = std::polar(rho, theta);
	return {z.real(), z.imag()};
}

double abs(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	return std::abs(z);
}

double arg(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	return std::arg(z);
}

double norm(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	return std::norm(z);
}

complex acos(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	std::complex<double> ans = std::acos(z);

	return {ans.real(), ans.imag()};
}

complex asin(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	std::complex<double> ans = std::asin(z);

	return {ans.real(), ans.imag()};
}

complex atan(complex x)
{
	std::complex<double> z {x.real(), x.imag()};
	std::complex<double> ans = std::atan(z);

	return {ans.real(), ans.imag()};
}


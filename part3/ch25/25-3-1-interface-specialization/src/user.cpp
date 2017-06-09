/*
 * user.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include <iostream>

#include "Complex.h"
using namespace std;

//constexpr Complex<int> ci1{1,2};
	// error: the type ‘const Complex<int>’ of constexpr variable ‘ci1’ is not literal

constexpr Complex<float> cf1{1.2F, 3.4F};
static_assert(cf1.real() == 1.2F && cf1.imag() == 3.4F, "surprising!");
constexpr Complex<float> cf2{cf1};
static_assert(cf1.real() == cf2.real() && cf1.imag() == cf2.imag(), "surprising!");
constexpr Complex<float> cf3 = cf2;
static_assert(cf3.real() == cf2.real() && cf3.imag() == cf2.imag(), "surprising!");

constexpr Complex<double> cd1{1.2, 3.4};
static_assert(cd1.real() == 1.2 && cd1.imag() == 3.4, "surprising!");

constexpr Complex<double> cd2{cf1};
static_assert(cd2.real() == 1.2F && cd2.imag() == 3.4F, "surprising!");

constexpr Complex<double> cd3 = cf1;
static_assert(cd3.real() == 1.2F && cd3.imag() == 3.4F, "surprising!");

constexpr Complex<float> cf4{cd1};
static_assert(cf4.real() == 1.2F && cf4.imag() == 3.4F, "surprising!");

//constexpr Complex<float> cf5 = cd1;
	// error: call to non-constexpr function ‘Complex<float>::Complex(const Complex<X>&) [with X = double]’
//static_assert(cf5.real() == 1.2F && cf5.imag() == 3.4F, "surprising!");

void test_complex_double()
{
	cout << "-- test_complex_double() --\n";
	Complex<double> z1{1.0, -2.0}, z2;
	cout << "z1: " << z1 << endl;
	cout << "z2: " << z2 << endl;

	z2 = z1;
	cout << "z2(=z1): " << z2 << endl;

	z2 += 1.2;
	cout << "z2(z2+=1.2): " << z2 << endl;

	z2 = 2.3;
	cout << "z2(=2.3): " << z2 << endl;

	Complex<float> f1{1.2F, 3.4F}, f2{5.6F, 7.8F};
	cout << "f1: " << f1 << endl;
	cout << "f2: " << f2 << endl;

	z1 = f1;
	cout << "z1(=f1): " << z1 << endl;

	z1 += f2;
	cout << "z1(z1+=f2): " << z1 << endl;

	Complex<double> z3{f1};
	cout << "z3{f1}: " << z3 << endl;
}

void test_complex_float()
{
	cout << "-- test_complex_float() --\n";
	Complex<float> f1{1.0F, -2.0F}, f2;
	cout << "f1: " << f1 << endl;
	cout << "f2: " << f2 << endl;

	f2 = f1;
	cout << "f2(=f1): " << f2 << endl;

	f2 += 1.2;
	cout << "f2(+=1.2): " << f2 << endl;

	f2 = 2.3;
	cout << "f2(=2.3): " << f2 << endl;

	Complex<double> d1{1.2, 3.4}, d2{-1, -2};
	cout << "d1: " << d1 << endl;
	cout << "d2: " << d2 << endl;

	f1 += d1;
	cout << "f1(+=d1): " << f1 << endl;
	f1 = d2;
	cout << "f1(=d2): " << f1 << endl;

	Complex<float> f3{d1};
	cout << "f3{d1}: " << f3 << endl;
}

void test_complex_int()
{
	cout << "-- test_complex_int() --\n";

	Complex<int> i1{1, -2}, i2;
	cout << "i1: " << i1 << endl;
	cout << "i2: " << i2 << endl;

	i2 = i1;
	cout << "i2(=i1): " << i2 << endl;

	i2 += 3;
	cout << "i2(+3): " << i2 << endl;

	i2 = 2;
	cout << "i2(=2): " << i2 << endl;

	Complex<double> z1{1.2, 3.4}, z2{4.5, 5.6};
	cout << "z1: " << z1 << endl;
	cout << "z2: " << z2 << endl;

	i1 += z1;
	cout << "i1(+=z1): " << i1 << endl;

	i1 = z2;
	cout << "i1(=z2): " << i1 << endl;

	Complex<int> i3{z1};
	cout << "i3{z1}: " << i3 << endl;
}

// add main

int main()
{
	test_complex_double();
	test_complex_float();
	test_complex_int();
}

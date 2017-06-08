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

constexpr Complex<double> cd1{1.2, 3.4};
static_assert(cd1.real() == 1.2 && cd1.imag() == 3.4, "surprising!");

constexpr Complex<double> cd2{cf1};
static_assert(cd2.real() == 1.2F && cd2.imag() == 3.4F, "surprising!");

void test_complex_double()
{
	cout << "-- test_complex_double() --\n";
	Complex<double> z1{1.0, -2.0};
	Complex<double> z2{z1};
	z1 = z2;
	z2 = 2.3;
	z2 += 1.2;

	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';
}

void test_complex_float()
{
	cout << "-- test_complex_float() --\n";
	Complex<float> f1{1.0F, -2.0F};
	Complex<float> f2{f1};
	f1 = f2;
	f2 = 2.3;
	f2 += 1.2;

	cout << "f1: " << f1 << '\n';
	cout << "f2: " << f2 << '\n';
}

void test_complex_double_float()
{
	cout << "-- test_complex_double_float() --\n";

	Complex<double> z1{1.2, 3.4}, z2{5.6, 7.8};
	Complex<float> f1{1.2F, 3.4F}, f2{5.6F, 7.8F};

	z1 = f1;
	z2 += f2;

	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';
}

void test_complex_int()
{
	cout << "-- test_complex_int() --\n";

	Complex<int> i1{1, -2};
	Complex<int> i2{i1};
	i1 = i2;
	i2 = 2;
	i2 += 3;

	cout << "i1: " << i1 << '\n';
	cout << "i2: " << i2 << '\n';

	Complex<double> z1{1.2, 3.4}, z2{4.5, 5.6};
	Complex<int> i3{z1};
	cout << "i3: " << i3 << endl;

	i3 = z2;
	cout << "i3 = z2; i3: " << i3 << endl;

	i3 += z1;
	cout << "i3 = z1; i3: " << i3 << endl;
}

// add main

int main()
{
	test_complex_double();
	test_complex_float();
	test_complex_double_float();
	test_complex_int();
}

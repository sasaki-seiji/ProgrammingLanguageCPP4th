/*
 * user.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include "complex.h"
#include <iostream>
using namespace std;

// add main

int main()
{
	complex<double> z1{1.0, -2.0};
	complex<double> z2{z1};
	z1 = z2;
	z2 = 2.3;
	z2 += 1.2;

	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	complex<float> f1{1.0F, -2.0F};
	complex<float> f2{f1};
	f1 = f2;
	f2 = 2.3;
	f2 += 1.2;

	cout << "f1: " << f1 << '\n';
	cout << "f2: " << f2 << '\n';

	z1 = f1;
	z2 += f2;

	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	complex<int> i1{1, -2};
	complex<int> i2{i1};
	i1 = i2;
	i2 = 2;
	i2 += 3;

	cout << "i1: " << i1 << '\n';
	cout << "i2: " << i2 << '\n';
}

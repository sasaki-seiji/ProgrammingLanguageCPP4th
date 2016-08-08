/*
 * user.cpp
 *
 *  Created on: 2016/08/08
 *      Author: sasaki
 */

#include "complex.h"
#include <iostream>
using namespace std;

constexpr complex z {10, -3};

int main()
{
	complex z1 {10, -3};
	complex z2 {10, 20};

	cout << "z: " << z << '\n';
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	if (z == z1) cout << "z == z1" << '\n';
	else cout << "!(z == z1)" << '\n';
	if (z == z2) cout << "z == z2" << '\n';
	else cout << "!(z == z2)" << '\n';

	z1.real(-2);
	cout << "z1.real(-2); z1: " << z1 << '\n';

	z1.imag(100);
	cout << "z1.imag(100); z1: " << z1 << '\n';
}



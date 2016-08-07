/*
 * user.cpp
 *
 *  Created on: 2016/08/07
 *      Author: sasaki
 */


#include "complex.h"
#include <iostream>
using namespace std;

void f(complex x, complex y)
{
	auto r1 = x+y;
	auto r2 = x+2;
	auto r3 = 2+x;
	auto r4 = 2+3;

	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	cout << "r1(x+y): " << r1 << '\n';
	cout << "r2(x+2): " << r2 << '\n';
	cout << "r3(2+x): " << r3 << '\n';
	cout << "r4(2+3): " << r4 << '\n';
}

// add main

int main()
{
	complex x{2,1}, y{-1, 3};
	f(x, y);
}

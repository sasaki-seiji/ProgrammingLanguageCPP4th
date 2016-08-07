/*
 * user.cpp
 *
 *  Created on: 2016/08/07
 *      Author: sasaki
 */


#include "complex.h"
#include <iostream>
using namespace std;

complex b {3};

void comp(complex x)
{
	cout << "comp():\n";

	x = 4;
	cout << "x: " << x << '\n';
}

void f()
{
	cout << "f():\n";

	complex z;
	complex x {1,2};
	complex y {x};
	z = x;

	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	cout << "z: " << z << '\n';
}

// add main

int main()
{
	cout << "b: " << b << '\n';
	complex x{-2,3};
	comp(x);
	f();
}

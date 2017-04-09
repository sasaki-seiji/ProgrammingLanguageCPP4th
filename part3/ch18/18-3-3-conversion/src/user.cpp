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
	cout << "-- comp() --\n";

	x = 4;
	cout << "x: " << x << '\n';
}

void f()
{
	cout << "-- f() --\n";

	complex z;
	cout << "complex z; " << z << '\n';

	complex x {1,2};
	cout << "complex x{1,2}; " << x << '\n';

	complex y {x};
	cout << "complex y{x}; " << y << '\n';

	z = x;
	cout << "z = x; " << z << '\n';
}

// add main

int main()
{
	cout << "b: " << b << '\n';
	complex x{-2,3};
	comp(x);
	f();
}

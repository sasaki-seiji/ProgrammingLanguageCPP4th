/*
 * user.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */


#include "complex.h"
#include <iostream>
using namespace std;

void f(complex x, complex y, complex z)
{
	complex r1 {x+y+z};
	complex r2 {x};
	r2 += y;
	r2 += z;

	cout << "r1: " << r1 << '\n';
	cout << "r2: " << r2 << '\n';
}

// add main

int main()
{
	complex x {1,0}, y{0,1}, z{2, -3};

	f(x, y, z);
}

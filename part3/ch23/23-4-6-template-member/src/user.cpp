/*
 * user.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */


#include "complex.h"
#include <iostream>
using namespace std;


complex<float> cf;
complex<double> cd {cf};
complex<float> cf2 {cd};
	// warning: narrowing conversion of '(& c)->complex<Scalar>::real<double>()' from 'double' to 'float' inside { } [-Wnarrowing]
	// warning: narrowing conversion of '(& c)->complex<Scalar>::imag<double>()' from 'double' to 'float' inside { } [-Wnarrowing]

complex<float> cf3 {2.0, 3.0};
	// warning: narrowing conversion of 'rr' from 'double' to 'float' inside { } [-Wnarrowing]
	// warning: narrowing conversion of 'ii' from 'double' to 'float' inside { } [-Wnarrowing]
complex<double> cd2 {2.0F, 3.0F};


class Quad {
};

complex<Quad> cq;
//complex<int> ci {cq};
	// error: cannot convert '<brace-enclosed initializer list>' to 'int' in initialization

// add main

int main()
{
	cout << "cf: " << cf << '\n';
	cout << "cd: " << cd << '\n';
	cout << "cf2: " << cf2 << '\n';

	cout << "cf3: " << cf3 << '\n';
	cout << "cd2: " << cd2 << '\n';
}


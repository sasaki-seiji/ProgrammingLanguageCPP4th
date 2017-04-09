/*
 * user.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include "complex.h"
#include <iostream>
using namespace std;

void f()
{
	cout << "-- f() --\n";
	complex a = complex{1, 3.1};
	complex b {1.2, 2};
	complex c {b};

	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	cout << "c: " << c << '\n';

	cout << "a+b: " << a+b << '\n';
	cout << "a*b: " << a*b << '\n';

	a = a+c;
	cout << "a=a+c: " << a << '\n';

	b = b+c*a;
	cout << "b=b+c*a: " << b << '\n';

	c = a*b+complex(1,2);
	cout << "c=a*b+complex(1,2): " << c << '\n';
}

// add main

int main()
{
	f();
}


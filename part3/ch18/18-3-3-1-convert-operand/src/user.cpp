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
	cout << "-- f(complex, complex) --\n";
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';

	cout << boolalpha;
	cout << "x==y: " << (x==y) << '\n';
	cout << "x==3: " << (x==3) << '\n';
	cout << "3==y: " << (3==y) << '\n';
}


void g(complex z)
{
	cout << "-- g(complex: " << z << ") --\n";

	complex ans = 3+z;
	cout << "3+z: " << ans << endl;

	//3.operator+=(z);
		// error: unable to find numeric literal operator 'operator""operator'
	//3+=z;
		// error: no match for 'operator+=' (operand types are 'int' and 'complex')
}

// add main

int main()
{
	complex x1{3,0}, y1{3, 0}, x2{1,2}, y2{-1,-3};
	f(x1, y1);
	f(x2, y2);

	g(x2);

	complex x {4,5};
	complex z {sqrt(x)+={1,2}};

	cout << "x: " << x << '\n';
	cout << "z: " << z << '\n';
}

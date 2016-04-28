/*
 * conversion.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(double d)
{
	char c = d;
		// conversion to 'char' from 'double' may alter its value [-Wfloat-conversion]

	cout << "int{c}: " << int{c} << '\n';
}

void f2(double d)
{
	char c {d};
		// narrowing conversion of 'd' from 'double' to 'char' inside { } [-Wnarrowing]
		// conversion to 'char' from 'double' may alter its value [-Wfloat-conversion]

	cout << "int{c}: " << int{c} << '\n';
}

int main()
{
	f(10.5);
	f2(5.5);
}

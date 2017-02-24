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

	cout << "int{c}: " << int{c} << '\n';
}

void f2(double d)
{
	char c {d};
		// warning: narrowing conversion of 'd' from 'double' to 'char' inside { } [-Wnarrowing]

	cout << "int{c}: " << int{c} << '\n';
}

int main()
{
	f(10.5);
	f2(5.5);
}

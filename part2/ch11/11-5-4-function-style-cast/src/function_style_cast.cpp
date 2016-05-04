/*
 * function_style_cast.cpp
 *
 *  Created on: 2016/05/04
 *      Author: sasaki
 */

#include <complex>
#include <iostream>
using namespace std;

void f(double d)
{
	int i = int(d);
	//complex z = complex(d);
	complex<double> z = complex<double>(d);

	cout << "i: " << i << '\n';
	cout << "z: " << z << '\n';
}

void f(double d, char* p)
{
	int a = int(d);
	//int b = int(p);
		// cast from 'char*' to 'int' loses precision [-fpermissive]
	//int c = (int)p;
		// cast from 'char*' to 'int' loses precision [-fpermissive]

	cout << "a: " << a << '\n';
}

int main()
{
	f(5.6);

	char c = 'a';
	f(7.8, &c);
}


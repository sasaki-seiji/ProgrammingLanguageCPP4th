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
	cout << "-- f(double:" << d << ") --\n";

	int i = int(d);
	//complex z = complex(d);
	complex<double> z = complex<double>(d);

	cout << "i = " << i << '\n';
	cout << "z = " << z << '\n';
}

void f(double d, char* p)
{
	cout << "-- f(double:" << d << ",char*) --\n";

	int a = int(d);
	//int b = int(p);
		// error: cast from 'char*' to 'int' loses precision [-fpermissive]
	long lb = (long)p;
	//int c = (int)p;
		// error: cast from 'char*' to 'int' loses precision [-fpermissive]
	long lc = (long)p;

	cout << "a = " << a << '\n';
	cout << "lb = " << lb << endl;
	cout << "lc = " << lc << endl;
}

int main()
{
	f(5.6);

	char c = 'a';
	f(7.8, &c);
}


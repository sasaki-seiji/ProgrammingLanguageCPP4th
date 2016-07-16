/*
 * user.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date.h"
#include "Date2.h"
#include <complex>
#include <iostream>
using namespace std;

complex<double> d {1};

void my_fct(Date d);

void f()
{
	cout << "enter f():\n";

	Date d {15};
	d.print();

	my_fct(15);

	d = 16;
	d.print();

	cout << "return f()\n";
}

Date2 d1 {15};
Date2 d2 = Date2{15};
//Date2 d3 = {15};
	// converting to 'Date2' from initializer list would use explicit constructor 'Date2::Date2(int, int, int)'
//Date2 d4 = 15;
	// conversion from 'int' to non-scalar type 'Date2' requested

void my_fct2(Date2 d)
{
	d.print();
}

void f2()
{
	cout << "enter f2()\n";

	//my_fct2(15);
		// could not convert '15' from 'int' to 'Date2'
	//my_fct2({15});
		// converting to 'Date2' from initializer list would use explicit constructor 'Date2::Date2(int, int, int)'
	my_fct2(Date2{15});

	cout << "return f2()\n";
}
// define undef-func
void my_fct(Date d)
{
	d.print();
}

// add main
int main()
{
	cout << "d: " << d << '\n';

	f();

	cout << "d1: " ; d1.print();
	cout << "d2: " ; d2.print();

	f2();
}


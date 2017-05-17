/*
 * enable_if.cpp
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

#include "Smart_pointer.h"
#include <complex>
#include <iostream>
using namespace std;

void f(Smart_pointer<double> p, Smart_pointer<complex<double>> q)
{
	auto d0 = *p;
	auto c0 = *q;
	auto d1 = q->real();
	//auto d2 = p->real();
		// base operand of '->' has non-pointer type 'Smart_pointer<double>'

	cout << "d0: " << d0 << '\n';
	cout << "c0: " << c0 << '\n';
	cout << "d1: " << d1 << '\n';
}

// add main

int main()
{
	Smart_pointer<double> p(new double{1.2});
	Smart_pointer<complex<double>> q(new complex<double>{2.3, 4.5});
	f(p,q);
}

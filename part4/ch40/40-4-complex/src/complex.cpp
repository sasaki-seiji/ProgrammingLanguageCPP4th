/*
 * complex.cpp
 *
 *  Created on: 2017/01/12
 *      Author: sasaki
 */


#include <complex>
#include <iostream>
using namespace std;

int main()
{
	complex<float> z1 = 1.33333333333333333;
	complex<double> z2 = 1.33333333333333333;
	z1=z2;

	complex<float> z3 { 1.33333333333333333 };	// not error!

	cout << "z1=" << z1 << endl;
	cout << "z2=" << z2 << endl;
	cout << "z3=" << z3 << endl;
}

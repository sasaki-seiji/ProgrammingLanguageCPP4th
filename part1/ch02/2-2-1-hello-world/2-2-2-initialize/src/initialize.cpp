/*
 * initialize.cpp
 *
 *  Created on: 2016/03/19
 *      Author: sasaki
 */

#include <iostream>
#include <complex>
#include <vector>
using namespace std;

int main()
{
	double d1 = 2.3;
	double d2 {2.3};

	complex<double> z = 1;
	complex<double> z2 {d1, d2};
	complex<double> z3 = {1, 2};

	vector<int> v {1,2,3,4,5,6};

	// 2016.03.19 add
	cout << "z = " << z << ", z2 = " << z2 << ", z3 = " << z3 << endl;
	//cout << "v = " << v << endl; // compile error

	int i1 = 7.2;
	//int i2 {7.2};
		// error: narrowing conversion of ‘7.2000000000000002e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]
	//int i3 = {7.2};
		// error: narrowing conversion of ‘7.2000000000000002e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]

	cout << "i1 = " << i1 << endl;
}



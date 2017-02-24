/*
 * float_conversion.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <cfloat>
#include <limits>
#include <iostream>
using namespace std;

float f = FLT_MAX;
double d = f;
double d2 = DBL_MAX;
float f2 = d2;
long double ld = d2;
long double ld2 = numeric_limits<long double>::max();
double d3 = ld2;

int main()
{
	cout << "f(FLT_MAX): " << f << '\n';
	cout << "d(=f): " << d << '\n';
	cout << "d2(DBL_MAX): " << d2 << '\n';
	cout << "f2(=d2): " << f2 << '\n';
	cout << "ld(=d2): " << ld << '\n';
	cout << "ld2(<long double>::max()): " << ld2 << '\n';
	cout << "d3(=ld2): " << d3 << '\n';
}


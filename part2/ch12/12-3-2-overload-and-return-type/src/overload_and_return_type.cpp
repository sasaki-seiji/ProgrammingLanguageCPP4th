/*
 * overload_and_return_type.cpp
 *
 *  Created on: 2016/05/08
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

float sqrt(float);
double sqrt(double);

void f(double da, float fla)
{
	float fl = sqrt(da);
	double d = sqrt(da);
	cout << "fl: << " << fl << ", d: " << d << '\n';

	fl = sqrt(fla);
	d = sqrt(fla);
	cout << "fl: << " << fl << ", d: " << d << '\n';
}

int main()
{
	double d = 1.2e200;
	float fl = 5.6e20f;

	f(d, fl);
}

float sqrt(float fl)
{
	cout << "sqrt(float: " << fl << ")\n";
	return fl;
}
double sqrt(double d)
{
	cout << "sqrt(double: " << d << ")\n";
	return d;
}

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
	cout << "-- f(double:" << da << ",float:" << fla << ") --\n";

	float fl = sqrt(da);
	double d = sqrt(da);
	cout << "fl = sqrt(da):" << fl << ", d = sqrt(da):" << d << '\n';

	fl = sqrt(fla);
	d = sqrt(fla);
	cout << "fl = sqrt(fla):" << fl << ", d = sqrt(fla):" << d << '\n';
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

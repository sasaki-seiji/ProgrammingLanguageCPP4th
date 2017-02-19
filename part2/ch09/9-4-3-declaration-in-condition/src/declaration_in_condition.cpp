/*
 * declaration_in_condition.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

double prim(bool);

double f1(double left)
{
	cout << "-- f1(" << left << ") --\n";

	if (double d = prim(true)) {
		left /= d;
	}

	cout << "f1(double) = " << left << "\n";
	return left;
}

double f2(double left)
{
	cout << "-- f2(" << left << ") --\n";

	double d2;
	double d;

	d2 = d;
		// warning: 'd' is used uninitialized in this function [-Wuninitialized]

	if (d = prim(true)) {
		left /= d;
	}

	d = 2.0;

	cout << "f2(double) = " << left << '\n';
	return left;
}

int main()
{
	f1(2.3);
	f2(3.4);
}

// undef reference
double prim(bool b)
{
	if (b) return 1.1;
	else return 0.0;
}

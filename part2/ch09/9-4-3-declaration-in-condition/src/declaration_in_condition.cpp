/*
 * declaration_in_condition.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

double prim(bool);

double f1(double left)
{
	if (double d = prim(true)) {
		left /= d;
	}
	return left;
}

double f2(double left)
{
	double d2;
	double d;

	d2 = d;
		// 'd' is used uninitialized in this function [-Wuninitialized]

	if (d = prim(true)) {
		left /= d;
	}

	d = 2.0;
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

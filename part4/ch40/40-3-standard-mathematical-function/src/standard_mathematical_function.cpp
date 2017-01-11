/*
 * standard_mathematical_function.cpp
 *
 *  Created on: 2017/01/11
 *      Author: sasaki
 */

#include <cmath>
#include <cerrno>
#include <limits>
#include <iostream>
using namespace std;

void f()
{
	errno = 0;
	sqrt(-1);
	if (errno==EDOM) cerr << "sqrt() not defined for negative argument\n";
	pow(numeric_limits<double>::max(),2);
	if (errno==ERANGE) cerr << "result of pow() too large to represent as a double\n";
}

int main()
{
	f();
}

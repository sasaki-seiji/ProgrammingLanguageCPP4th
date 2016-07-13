/*
 * initialize_nonlocal_variable.cpp
 *
 *  Created on: 2016/07/13
 *      Author: sasaki
 */

#include <cmath>

double x = 2;
double y;
double sqx = sqrt(x+y);

int& use_count()
{
	static int uc = 0;
	return uc;
}

// add main
#include <iostream>
using namespace std;
int main()
{
	cout << "sqx: " << sqx << '\n';
	cout << "++use_count(): " << ++use_count() << '\n';
	cout << "++use_count(): " << ++use_count() << '\n';
}


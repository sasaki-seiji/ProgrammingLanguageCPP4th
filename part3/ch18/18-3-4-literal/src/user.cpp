/*
 * user.cpp
 *
 *  Created on: 2016/08/08
 *      Author: sasaki
 */


#include "complex.h"
#include <iostream>
using namespace std;

complex z1 {1.2, 12e3};
constexpr complex z2 {1.2, 12e3};

complex z3 {1.2+12e3i};

complex f(double d)
{
	auto x {2.3i};
	return x+sqrt(d+12e3i)+12e3i;
}

complex f2(double d)
{
	complex x {0, 2.3};
	return x+sqrt(complex{d,12e3})+complex{0,12e3};
}


// add main

int main()
{
	cout << "z1: " << z1 << '\n';
	cout << "z2: " << z2 << '\n';

	cout << "z3: " << z3 << '\n';

	complex ans = f(10.0);
	cout << "ans=f(10.0): " << ans << '\n';

	complex ans2 = f2(10.0);
	cout << "ans2=f2(10.0): " << ans2 << '\n';
}

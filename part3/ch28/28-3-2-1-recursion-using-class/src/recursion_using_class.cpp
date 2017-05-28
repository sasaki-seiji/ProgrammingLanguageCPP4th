/*
 * recursion_using_class.cpp
 *
 *  Created on: 2016/10/07
 *      Author: sasaki
 */

#include "Fac.h"
#include <iostream>
using namespace std;

constexpr int x7 = Fac<7>::value;
static_assert(x7 == 5040, "compile time check fails");

// add main

int main()
{
	cout << "x7: " << x7 << '\n';
}


/*
 * repetition_and_recrusion.cpp
 *
 *  Created on: 2016/10/07
 *      Author: sasaki
 */

#include "fac.h"
#include <iostream>
using namespace std;

constexpr int x5 = fac<5>();
static_assert(x5 == 120, "compile time check fails");

constexpr int x6 = fac2(6);
static_assert(x6 == 720, "compile time check fails");

// add main
int main()
{
	cout << "x5: " << x5 << '\n';
	cout << "x6: " << x6 << '\n';
}

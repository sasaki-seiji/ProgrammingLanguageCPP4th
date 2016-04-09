/*
 * variadic_template.cpp
 *
 *  Created on: 2016/03/30
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "variadic_template.h"

int main()
{
	cout << "first: ";
	f(1, 2.2, "hello");

	cout << "\nsecond: ";
	f(0.2, 'c', "yuck!", 0, 1, 2);
	cout << "\n";
}



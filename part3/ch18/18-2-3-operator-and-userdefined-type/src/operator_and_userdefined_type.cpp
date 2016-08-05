/*
 * operator_and_userdefined_type.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

enum Day { sun, mon, tue, wed, thu, fri, sat };

Day& operator++(Day& d)
{
	return d = (sat == d) ? sun : static_cast<Day>(d+1);
}

// add main

int main()
{
	Day d1 = mon, d2 = sat;

	++d1;
	++d2;

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
}

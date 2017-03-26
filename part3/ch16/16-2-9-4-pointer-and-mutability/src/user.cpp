/*
 * user.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

void f(Date d, const Date cd)
{
	string s1 = d.string_rep();
	string s2 = cd.string_rep();

	cout << "s1 = " << s1 << '\n';
	cout << "s2 = " << s2 << '\n';
}

// add main
int main()
{
	Date d1;
	const Date d2{25, 12, 1959};

	f(d1, d2);

	cout << "-- d1.add_day(1) --\n";
	d1.add_day(1);

	string s1 = d1.string_rep();
	string s2 = d2.string_rep();

	cout << "s1 = " << s1 << '\n';
	cout << "s2 = " << s2 << '\n';
}

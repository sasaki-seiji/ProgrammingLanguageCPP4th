/*
 * Date2.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date2.h"
#include <iostream>
using namespace std;

Date2 today {16, 7, 2016};

Date2::Date2(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

Date2::Date2(int dd, int mm) {
	d = dd;
	m = mm;
	y = today.y;
}

Date2::Date2(int dd) {
	d = dd;
	m = today.m;
	y = today.y;
}

Date2::Date2() {
	d = today.d;
	m = today.m;
	y = today.y;
}

Date2::Date2(const char* str)
{
	// dummy
	d = today.d;
	m = today.m;
	y = today.y;
}

void Date2::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

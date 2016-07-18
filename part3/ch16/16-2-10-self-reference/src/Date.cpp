/*
 * Date.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

struct { int d, m, y; } date_initializer = {1, 1, 1970};

Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : date_initializer.d;
	m = mm ? mm : date_initializer.m;
	y = yy ? yy : date_initializer.y;
}

Date& Date::add_year(int n)
{
	if (d == 29 && m == 2 && !leapyear(y+n)) {
		d = 1;
		m = 3;
	}
	y += n;
	return *this;
}

Date& Date::add_month(int n)
{
	m += n;
	return *this;
}

Date& Date::add_day(int n)
{
	d += n;
	return *this;
}

void Date::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}


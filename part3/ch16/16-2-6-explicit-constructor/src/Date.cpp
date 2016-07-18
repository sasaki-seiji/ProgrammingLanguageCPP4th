/*
 * Date.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include <iostream>

#include "Date.h"
using namespace std;

static Date today {16, 7, 2016};

Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : today.d;
	m = mm ? mm : today.m;
	y = yy ? yy : today.y;
}

void Date::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

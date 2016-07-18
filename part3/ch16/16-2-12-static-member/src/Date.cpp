/*
 * Date.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : default_date.d;
	m = mm ? mm : default_date.m;
	y = yy ? yy : default_date.y;
}

Date Date::default_date {16,12,1770};

void Date::set_default(int d, int m, int y)
{
	default_date = {d,m,y};
}

void Date::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

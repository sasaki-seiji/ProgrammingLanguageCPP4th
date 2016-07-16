/*
 * Date.cpp
 *
 *  Created on: 2016/07/16
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

void Date::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}


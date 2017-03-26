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

//int Date::year()
	// error: prototype for 'int Date::year()' does not match any in class 'Date'
int Date::year() const
{
	//return ++y;
		// error: increment of member 'Date::y' in read-only object

	return y;
}

void Date::print() const
{
	cout << y << '.' << m << '.' << d << '\n';
}


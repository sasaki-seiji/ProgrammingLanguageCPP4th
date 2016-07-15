/*
 * Date3.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date3.h"
#include <iostream>
using namespace std;

static Date3 today {16, 7, 2016};

Date3::Date3(int dd, int mm, int yy)
{
	d = dd ? dd : today.d;
	m = mm ? mm : today.m;
	y = yy ? yy : today.y;
}

void Date3::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

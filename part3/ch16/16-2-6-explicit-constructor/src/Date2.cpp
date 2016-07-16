/*
 * Date2.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date2.h"
#include <iostream>
using namespace std;

static Date2 today {16, 7, 2016};

Date2::Date2(int dd, int mm, int yy)
{
	d = dd ? dd : today.d;
	m = mm ? mm : today.m;
	y = yy ? yy : today.y;
}

void Date2::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}


/*
 * Date.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

void Date::init(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}

void Date::add_year(int n)
{
	y += n;
}
void Date::add_month(int n)
{
	m += n;
}
void Date::add_day(int n)
{
	d += n;
}

void Date::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}


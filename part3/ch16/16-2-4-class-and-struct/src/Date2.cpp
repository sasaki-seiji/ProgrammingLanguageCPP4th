/*
 * Date2.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date2.h"
#include <iostream>
using namespace std;

Date2::Date2(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

void Date2::add_year(int n)
{
	y += n;
}

void Date2::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

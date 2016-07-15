/*
 * Date1.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date1.h"
#include <iostream>
using namespace std;

Date1::Date1(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

void Date1::add_year(int n)
{
	y += n;
}

void Date1::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

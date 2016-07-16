/*
 * Date4.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date4.h"
#include <iostream>
using namespace std;

Date4::Date4(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

void Date4::add_year(int n)
{
	y += n;
}

void Date4::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

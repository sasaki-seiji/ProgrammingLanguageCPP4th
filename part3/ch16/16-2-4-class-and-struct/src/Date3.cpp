/*
 * Date3.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date3.h"
#include <iostream>
using namespace std;

Date3::Date3(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

void Date3::add_year(int n)
{
	y += n;
}

void Date3::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

/*
 * Date.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int dd, int mm, int yy) :d{dd}, m{mm}, y{yy} { }

Date::Date(int dd, int mm) : d{dd}, m{mm} { }

Date::Date(int dd) : d{dd} { }

Date::Date() { }

Date::Date(const char* str)
{
	// dummy
	d = date_initializer.d;
	m = date_initializer.m;
	y = date_initializer.y;
}

void Date::print()
{
	cout << y << '.' << m << '.' << d << '\n';
}

void print_initializer_address()
{
	cout << "in Date.cpp - &date_initializer: " << &date_initializer << '\n';
}

/*
 * Date.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

struct { int d, m, y; } date_initializer = {1, 1, 1970};

Date::Date(int dd, int mm, int yy)
	: cache_valid{false}, cache{ }
{
	d = dd ? dd : date_initializer.d;
	m = mm ? mm : date_initializer.m;
	y = yy ? yy : date_initializer.y;
}

int Date::year() const
{
	return y;
}

string Date::string_rep() const
{
	if (!cache_valid) {
		compute_cache_value();
		cache_valid = true;
	}
	return cache;
}

void Date::compute_cache_value() const
{
	string str;
	str += to_string(y);
	str += '.';
	str += to_string(m);
	str += '.';
	str += to_string(d);
	cache = str;
}


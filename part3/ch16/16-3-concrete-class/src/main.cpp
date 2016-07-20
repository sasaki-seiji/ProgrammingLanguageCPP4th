/*
 * main.cpp
 *
 *  Created on: 2016/07/20
 *      Author: sasaki
 */

#include "Date.h"
using namespace Chrono;

#include "user.h"
#include "test.h"

#include <vector>
using namespace std;

// add main
int main()
{
	Date d{29, Month::feb, 2016};
	f(d);

	vector<Date> vec;
	fill(vec);
	for (const Date& d : vec) {
		cout << d << '\n';
	}

	test_constructor();

	test_add_year();
	test_add_month();
	test_add_day();
}



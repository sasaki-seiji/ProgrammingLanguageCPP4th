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

	cout << boolalpha;
	test_operator_equal();
	test_operator_not_equal();
	test_operator_less_than();
	test_operator_greater_than();
	test_operator_increment();
	test_operator_decrement();
	test_operator_add_assign();
	test_operator_sub_assign();
	test_operator_add_int();
	test_operator_sub_int();
}



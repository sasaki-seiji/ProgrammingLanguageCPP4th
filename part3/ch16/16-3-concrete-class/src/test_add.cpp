/*
 * test_add.cpp
 *
 *  Created on: 2016/07/20
 *      Author: sasaki
 */

#include "Date.h"
using namespace Chrono;

#include <iostream>
using namespace std;

void test_add_year()
{
	cout << "\n--- test_add_year ---\n";

	Date d1{29, Month::feb, 2016};
	cout << "original date: " << d1 << '\n';
	cout << "after add_year(1): " << d1.add_year(1) << '\n';

	Date d2{1, Month::jan, 2016};
	cout << "original date: " << d2 << '\n';
	cout << "after add_year(5): " << d2.add_year(5) << '\n';

	Date d3{1, Month::jan, 2016};
	cout << "original date: " << d3 << '\n';
	cout << "after add_year(-5): " << d3.add_year(-5) << '\n';

	Date d4{1, Month::jan, 1};
	cout << "original date: " << d4 << '\n';
	try {
		cout << "try add_year(-1)\n";
		d4.add_year(-1) ;
		cout << "result d4 :" << d4 << '\n';
	} catch (Date::Bad_date&) {
		cout << "Bad_date\n";
	}
}

void test_add_month()
{
	cout << "\n--- test_add_month ---\n";

	Date d1{31, Month::jan, 1900};
	cout << "original date: " << d1 << '\n';
	cout << "after add_month(1): " << d1.add_month(1) << '\n';

	Date d2{30, Month::nov, 1900};
	cout << "original date: " << d2 << '\n';
	cout << "after add_month(2): " << d2.add_month(2) << '\n';

	Date d3{31, Month::aug, 1900};
	cout << "original date: " << d3 << '\n';
	cout << "after add_month(15): " << d3.add_month(15) << '\n';

	Date d4{31, Month::mar, 1900};
	cout << "original date: " << d4 << '\n';
	cout << "after add_month(-1): " << d4.add_month(-1) << '\n';

	Date d5{1, Month::feb, 1900};
	cout << "original date: " << d5 << '\n';
	cout << "after add_month(-2): " << d5.add_month(-2) << '\n';

	Date d6{31, Month::aug, 1900};
	cout << "original date: " << d6 << '\n';
	cout << "after add_month(-15): " << d6.add_month(-15) << '\n';

	Date d7{31, Month::jan, 1};
	cout << "original date: " << d7 << '\n';
	try {
		cout << "try add_month(-1)\n";
		d7.add_month(-1);
		cout << "result d7: " << d7 << '\n';
	} catch (Date::Bad_date&) {
		cout << "Bad_date\n";
	}
}

void test_add_day()
{
	cout << "\n--- test_add_day ---\n";

	Date d1{1, Month::jan, 2016};
	cout << "original date: " << d1 << '\n';
	cout << "after add_day(1): " << d1.add_day(1) << '\n';

	Date d2{31, Month::jan, 2016};
	cout << "original date: " << d2 << '\n';
	cout << "after add_day(1): " << d2.add_day(1) << '\n';

	Date d3{1, Month::dec, 2016};
	cout << "original date: " << d3 << '\n';
	cout << "after add_day(50): " << d3.add_day(50) << '\n';

	Date d4{31, Month::jan, 2016};
	cout << "original date: " << d4 << '\n';
	cout << "after add_day(-1): " << d4.add_day(-1) << '\n';

	Date d5{1, Month::feb, 2016};
	cout << "original date: " << d5 << '\n';
	cout << "after add_day(-1): " << d5.add_day(-1) << '\n';

	Date d6{1, Month::feb, 2016};
	cout << "original date: " << d6 << '\n';
	cout << "after add_day(-50): " << d6.add_day(-50) << '\n';

	Date d7{31, Month::dec, 1};
	cout << "original date: " << d7 << '\n';
	try {
		cout << "try add_day(-365)\n";
		d7.add_day(-365);
		cout << "result d7: " << d7 << '\n';
	} catch (Date::Bad_date&) {
		cout << "Bad_date\n";
	}
}

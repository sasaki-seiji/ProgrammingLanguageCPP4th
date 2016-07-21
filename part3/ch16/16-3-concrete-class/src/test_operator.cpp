/*
 * test_operator.cpp
 *
 *  Created on: 2016/07/21
 *      Author: sasaki
 */

#include "Date.h"
using namespace Chrono;

#include <iostream>
using namespace std;

void test_operator_equal()
{
	cout << "\n--- test_operator_equal ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{14, Month::jun, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 == d2: " << (d1==d2) << '\n';
	cout << "d1 == d3: " << (d1==d3) << '\n';
}

void test_operator_not_equal()
{
	cout << "\n--- test_operator_not_equal ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{14, Month::jun, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 != d2: " << (d1!=d2) << '\n';
	cout << "d1 != d3: " << (d1!=d3) << '\n';
}

void test_operator_less_than()
{
	cout << "\n--- test_operator_less_than ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{14, Month::jun, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 < d2: " << (d1<d2) << '\n';
	cout << "d2 < d3: " << (d2<d3) << '\n';
	cout << "d3 < d1: " << (d3<d1) << '\n';
}

void test_operator_greater_than()
{
	cout << "\n--- test_operator_greater_than ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{14, Month::jun, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 > d2: " << (d1>d2) << '\n';
	cout << "d2 > d3: " << (d2>d3) << '\n';
	cout << "d3 > d1: " << (d3>d1) << '\n';
}

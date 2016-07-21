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

void test_operator_increment()
{
	cout << "\n--- test_operator_incremnt ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{30, Month::jun, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "++d1: " << ++d1 << '\n';
	cout << "++d2: " << ++d2<< '\n';
	cout << "++ ++ d3: " << ++ ++ d3 << '\n';
}

void test_operator_decrement()
{
	cout << "\n--- test_operator_decrement ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{1, Month::jan, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "--d1: " << --d1 << '\n';
	cout << "--d2: " << --d2<< '\n';
	cout << "-- -- d3: " << -- -- d3 << '\n';
}

void test_operator_add_assign()
{
	cout << "\n--- test_operator_add_assign ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{1, Month::jan, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 += 10: " << (d1 += 10) << '\n';
	cout << "d2 += -1: " << (d2 += -1) << '\n';
	cout << "++(d3 += 10): " << ++(d3 += 10) << '\n';
}

void test_operator_sub_assign()
{
	cout << "\n--- test_operator_sub_assign ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{1, Month::jan, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 -= 10: " << (d1 -= 10) << '\n';
	cout << "d2 -= 1: " << (d2 -= 1) << '\n';
	cout << "--(d3 -= 10): " << --(d3 -= 10) << '\n';
}

void test_operator_add_int()
{
	cout << "\n--- test_operator_add_int ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{1, Month::jan, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 + 10: " << d1 + 10 << '\n';
	cout << "d2 + 10 + 20: " << d2 + 10 + 20 << '\n';
	cout << "d3 + 100: " << d3 + 100 << '\n';
}

void test_operator_sub_int()
{
	cout << "\n--- test_operator_sub_int ---\n";

	Date d1{13, Month::jun, 2000};
	Date d2{1, Month::jan, 2000};
	Date d3{13, Month::jun, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d1 - 10: " << d1 - 10 << '\n';
	cout << "d2 - 10 - 20: " << d2 - 10 - 20 << '\n';
	cout << "d3 - 100: " << d3 - 100 << '\n';
}

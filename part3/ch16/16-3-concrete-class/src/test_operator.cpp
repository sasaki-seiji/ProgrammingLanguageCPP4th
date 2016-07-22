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

	Date d1{13, Month::feb, 2000};
	Date d2{13, Month::mar, 1999};
	Date d3{13, Month::jan, 2001};
	Date d4{14, Month::jan, 2000};
	Date d5{12, Month::mar, 2000};
	Date d6{12, Month::feb, 2000};
	Date d7{14, Month::feb, 2000};
	Date d8{13, Month::feb, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d4: " << d4 << '\n';
	cout << "d5: " << d5 << '\n';
	cout << "d6: " << d6 << '\n';
	cout << "d7: " << d7 << '\n';
	cout << "d8: " << d8 << '\n';
	cout << "d1 < d2: " << (d1<d2) << '\n';
	cout << "d1 < d3: " << (d1<d3) << '\n';
	cout << "d1 < d4: " << (d1<d4) << '\n';
	cout << "d1 < d5: " << (d1<d5) << '\n';
	cout << "d1 < d6: " << (d1<d6) << '\n';
	cout << "d1 < d7: " << (d1<d7) << '\n';
	cout << "d1 < d8: " << (d1<d8) << '\n';
}

void test_operator_greater_than()
{
	cout << "\n--- test_operator_greater_than ---\n";

	Date d1{13, Month::feb, 2000};
	Date d2{13, Month::mar, 1999};
	Date d3{13, Month::jan, 2001};
	Date d4{14, Month::jan, 2000};
	Date d5{12, Month::mar, 2000};
	Date d6{12, Month::feb, 2000};
	Date d7{14, Month::feb, 2000};
	Date d8{13, Month::feb, 2000};

	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';
	cout << "d4: " << d4 << '\n';
	cout << "d5: " << d5 << '\n';
	cout << "d6: " << d6 << '\n';
	cout << "d7: " << d7 << '\n';
	cout << "d8: " << d8 << '\n';
	cout << "d1 > d2: " << (d1>d2) << '\n';
	cout << "d1 > d3: " << (d1>d3) << '\n';
	cout << "d1 > d4: " << (d1>d4) << '\n';
	cout << "d1 > d5: " << (d1>d5) << '\n';
	cout << "d1 > d6: " << (d1>d6) << '\n';
	cout << "d1 > d7: " << (d1>d7) << '\n';
	cout << "d1 > d8: " << (d1>d8) << '\n';
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

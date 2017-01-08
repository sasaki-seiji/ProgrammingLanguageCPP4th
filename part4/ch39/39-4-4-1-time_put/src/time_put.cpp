/*
 * time_put.cpp
 *
 *  Created on: 2016/12/31
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
#include <sstream>
using namespace std;

#include "Date.h"
using namespace Chrono;

void test_time_put()
{
	int year = 1999;
	int day = 5;
	for (int m = 1; m <=12 ; ++m, ++day) {
		Month month = static_cast<Month>(m);
		Date d {day, month, year};
		cout << d << endl;
	}

}

int main()
{
	Date d {25, Month::dec, 1959};
	cout << d << endl;

	cout << "--- en_US.UTF-8 ---\n";
	cout.imbue(locale{"en_US.UTF-8"});
	test_time_put();

	cout << "--- fr_FR.UTF-8 ---\n";
	cout.imbue(locale{"fr_FR.UTF-8"});
	test_time_put();
}

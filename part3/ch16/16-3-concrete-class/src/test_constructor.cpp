/*
 * test_constructor.cpp
 *
 *  Created on: 2016/07/20
 *      Author: sasaki
 */

#include "Date.h"
using namespace Chrono;

#include <iostream>
using namespace std;

Date d0;
Date d1{20};
Date d2{20,Month::feb};
Date d3{20,Month::feb,2000};

void test_constructor()
{
	cout << "\n--- test_constructor ---\n";

	cout << "d0: " << d0 << '\n';
	cout << "d1: " << d1 << '\n';
	cout << "d2: " << d2 << '\n';
	cout << "d3: " << d3 << '\n';

	try {
		Date d4{-1, Month::jan, 1970};
		cout << "d4: " << d4 << '\n';
	} catch (Date::Bad_date&) {
		cout << "Bad_date: Date{-1, Month::jan, 1970}\n";
	}
}


/*
 * time_get.cpp
 *
 *  Created on: 2016/12/31
 *      Author: sasaki
 */

#include <iostream>
#include <locale>
#include <sstream>
using namespace std;

#include "Date.h"
using namespace Chrono;


void test()
{
	//Date d1(3,10,1980);
	Date d1(3,Month::oct,1980);
	cout << d1 << '\n';

	auto order = use_facet<time_get<char>>(cin.getloc()).date_order();
	if (order == time_base::mdy)
		cout << "month day year\n";
	else
		cout << "poor guess: " << order << "\n";
	//stringstream ss ("10/4/1980");
	stringstream ss ("10/04/1980");
	ss.imbue(locale::classic());	// 2017.01.04 add
	ss >> d1;
	cout << d1 << '\n';
}

// 2017.01.09 add
void test_get_date(const locale& loc, const string& s)
{
	Date d;
	istringstream iss;
	iss.imbue(loc);
	iss.str(s);
	iss >> d;
	cout << d << endl;
}

int main()
{
	cin.imbue(locale::classic());	// 2017.01.04 add
	test();

	test_get_date(locale("en_US.UTF-8"), "04/10/1999");
	test_get_date(locale("fr_FR.UTF-8"), "10/12/2015");
}

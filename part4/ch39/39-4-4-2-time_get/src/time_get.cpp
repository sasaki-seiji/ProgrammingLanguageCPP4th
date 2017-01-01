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
	stringstream ss ("10/4/1980");
	ss >> d1;
	cout << d1 << '\n';
}

int main()
{
	cin.imbue(locale("en_US.UTF-8"));
	test();
}

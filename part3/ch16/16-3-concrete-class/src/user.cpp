/*
 * user.cpp
 *
 *  Created on: 2016/07/20
 *      Author: sasaki
 */

#include "Date.h"
using namespace Chrono;

#include "user.h"

#include <iostream>
using namespace std;

bool midnight() { return true; }

void f(Date& d)
{
	cout << "--- f(Date&) ---\n";

	Date lvb_day {16,Month::dec,d.year()};

	if (d.day()==29 && d.month()==Month::feb) {
		cout << "leap day\n";
	}

	if (midnight()) d.add_day(1);

	cout << "day after:" << d+1 << '\n';

	Date dd;
	cin>>dd;
	if (dd==d) cout << "Hurray!\n";
}

void fill(vector<Date>& aa)
{
	cout << "\n--- fill(vector<Date>&) ---\n";

	while (cin) {
		Date d;
		try {
			cin >> d;
		}
		//catch (Date::Bad_date) {
		catch (Date::Bad_date&) {
			// Catching by reference is recommended
			continue;
		}
		aa.push_back(d);
	}
}


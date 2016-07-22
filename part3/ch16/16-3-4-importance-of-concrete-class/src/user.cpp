/*
 * user.cpp
 *
 *  Created on: 2016/07/22
 *      Author: sasaki
 */


#include "Date.h"
#include "Time.h"
#include "Dateandtime.h"
using namespace Chrono;

#include <iostream>
using namespace std;

int main()
{
	Date d1{25, Month::dec, 1959};
	Time t1{10, 12, 33};
	Date_and_time dt1{d1, t1};
	Date_and_time dt2{25, Month::dec, 1959, t1};

	cout << "dt1: " << dt1 << '\n';
	cout << "dt2: " << dt2 << '\n';
}

/*
 * user.cpp
 *
 *  Created on: 2016/07/15
 *      Author: sasaki
 */

#include "Date.h"

Date my_birthday;

void f()
{
	Date today;

	today.init(16, 10, 1996);
	my_birthday.init(30, 12, 1950);

	Date tommorrow = today;
	tommorrow.add_day(1);

	today.print();
	my_birthday.print();
	tommorrow.print();
}

// add main
int main()
{
	f();
}


/*
 * default_copy.cpp
 *
 *  Created on: 2016/07/15
 *      Author: sasaki
 */

#include "Date.h"

Date my_birthday;

void f()
{
	my_birthday.init(30,12,1950);

	Date d1 = my_birthday;
	Date d2 {my_birthday};

	d1.print();
	d2.print();
}

void f(Date& d)
{
	d = my_birthday;
}

// add main
int main()
{
	f();

	Date d3;
	f(d3);
	d3.print();
}

/*
 * default_copy.cpp
 *
 *  Created on: 2016/07/15
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

Date my_birthday;

void f()
{
	cout << "-- copy-initialize Date objects --\n";

	my_birthday.init(30,12,1950);

	Date d1 = my_birthday;
	Date d2 {my_birthday};

	d1.print();
	d2.print();
}

void f(Date& d)
{
	cout << "-- copy-assign Date object --\n";
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

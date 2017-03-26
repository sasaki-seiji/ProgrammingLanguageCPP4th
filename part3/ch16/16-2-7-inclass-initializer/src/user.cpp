/*
 * user.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

Date d1 {};
Date d2 {25};
Date d3 {25,12};
Date d4 {25,12,1959};
Date d5 {"26 mar 2017"};

int main()
{
	Date d;
	d.print();

	d1.print();
	d2.print();
	d3.print();
	d4.print();
	d5.print();

	cout << "in user.cpp - &date_initializer: " << &date_initializer << '\n';
	print_initializer_address();
}



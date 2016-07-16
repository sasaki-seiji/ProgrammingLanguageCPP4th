/*
 * user.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date.h"

Date d1 {};
Date d2 {25};
Date d3 {25,12};
Date d4 {25,12,1959};

int main()
{
	d1.print();
	d2.print();
	d3.print();
	d4.print();

	d1.add_year(1);
	d2.add_month(2);
	d3.add_day(3);

	d1.print();
	d2.print();
	d3.print();
}



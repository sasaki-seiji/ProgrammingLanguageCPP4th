/*
 * user.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */


#include "Date.h"

void f(Date& d)
{
	d.add_day(1).add_month(1).add_year(1);
}

// add main
int main()
{
	Date d1;
	f(d1);

	Date d2{29, 2, 2016};
	d2.add_year(3);

	d1.print();
	d2.print();
}

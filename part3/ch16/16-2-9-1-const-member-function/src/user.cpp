/*
 * user.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

void f(Date& d, const Date& cd)
{
	cout << "-- f(Date&,const Date&) --\n";

	int i = d.year();
	d.add_year(1);
	int j = cd.year();
	//cd.add_year(1);
		// error: passing 'const Date' as 'this' argument discards qualifiers [-fpermissive]

	cout << "i = " << i << '\n';
	cout << "j = " << j << '\n';

	d.print();
	cd.print();
}

// add main
int main()
{
	Date d1;
	const Date d2{25, 12, 1959};

	f(d1, d2);
}

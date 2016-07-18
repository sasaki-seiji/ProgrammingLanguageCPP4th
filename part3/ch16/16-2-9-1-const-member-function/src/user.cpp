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
	int i = d.year();
	d.add_year(1);
	int j = cd.year();
	//cd.add_year(1);
		// passing 'const Date' as 'this' argument discards qualifiers [-fpermissive]

	cout << "i: " << i << '\n';
	cout << "j: " << j << '\n';
}

// add main
int main()
{
	Date d1;
	const Date d2{25, 12, 1959};

	f(d1, d2);
}

/*
 * user.cpp
 *
 *  Created on: 2016/10/14
 *      Author: sasaki
 */


#include "Tuple.h"
#include <iostream>
using namespace std;

int main()
{
	Tuple<double, int, char> x {1.1, 42, 'a'};
	get<2>(x) = 'b';
	cout << x << '\n';

	const Tuple<double, int, char> xx {1.1, 42, 'a'};
	char cc = get<2>(xx);
	cout << "cc: " << cc << '\n';
	cout << "xx: " << xx << '\n';
	//get<2>(xx) = 'x';
		// error: assignment of read-only location 'get<2, double, int, char, Nil>(xx)'

}


/*
 * Club.cpp
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */

#include "Club.h"
#include <iostream>
using namespace std;

Club::Club(const string& n, Date fd)
	: name{n}, members{}, officers{}, founded{fd}
{
	cout << "Club::Club(" << n << "," << founded << ")\n";
}

void Club::print(ostream& os)
{
	os << "name: " << name << ", founded: " << founded << '\n';
}

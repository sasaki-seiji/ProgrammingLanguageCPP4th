/*
 * localization.cpp
 *
 *  Created on: 2016/12/31
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
#include <sstream>
using namespace std;

#include "Date.h"
using namespace Chrono;

void cpy(istream& is, ostream& os)
{
	Date d;
	double volume;

	while (is >> d >> volume)
		os << d << ' ' << '\n';
}


void test_cpy()
{
	//istringstream iss{"Apr 12, 1999  1000.3"};
	istringstream iss{"10/3/1999  1000.3"};
//	iss.imbue(locale{"en_US.UTF-8"});
//	cout.imbue(locale{"fr_FR.UTF-8"});
	cpy(iss, cout);
}

int main()
{
	test_cpy();
}

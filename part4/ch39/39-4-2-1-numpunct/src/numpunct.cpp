/*
 * format_number.cpp
 *
 *  Created on: 2017/01/02
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

#include "My_punct.h"

void f()
{
	cout << "style A: " << 12345678
			<< " *** " << 1234567.8
			<< " *** " << fixed << 1234567.8 << '\n';
	cout << defaultfloat;
	locale loc(locale(),new My_punct);
	cout.imbue(loc);
	cout << "style B: " << 12345678
			<< " *** " << 1234567.8
			<< " *** " << fixed << 1234567.8 << '\n';
}

void test_numpunct(const locale& loc)
{
	cout << "-- " << loc.name() << " --\n";
	cout.imbue(loc);
	cout << 123456789 << endl;
	cout << defaultfloat << 12345678.9 << endl;
	cout << fixed << 12345678.9 << endl;
	cout << boolalpha << "true: " << true << ", false: " << false << endl;
}

int main()
{
	f();

	test_numpunct(locale("en_US.UTF-8"));
	test_numpunct(locale("fr_FR.UTF-8"));
	test_numpunct(locale("da_DK"));
	test_numpunct(locale(""));
}


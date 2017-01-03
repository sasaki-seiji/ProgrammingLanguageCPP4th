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

int main()
{
	f();
}


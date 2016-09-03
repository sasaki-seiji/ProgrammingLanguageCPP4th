/*
 * BBdial.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBdial.h"
#include <iostream>
using namespace std;

void BBdial::prompt(const char* name)
{
	cout << "(BBdial) enter value into " << name << ": " << flush ;

	int v;
	cin >> v;
	value(v);
}


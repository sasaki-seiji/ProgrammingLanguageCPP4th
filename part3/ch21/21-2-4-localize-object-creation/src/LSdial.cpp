/*
 * LSdial.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "LSdial.h"
#include <iostream>
using namespace std;

void LSdial::prompt(const char* name)
{
	cout << "(LSdial) enter value into " << name << ": " << flush ;

	int v;
	cin >> v;
	set_value(v);
}


/*
 * LSslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "LSslider.h"
#include <iostream>
using namespace std;

void LSslider::prompt(const char* name)
{
	cout << "(LSslider) enter value into " << name << ": " << flush ;

	int v;
	cin >> v;
	set_value(v);
}


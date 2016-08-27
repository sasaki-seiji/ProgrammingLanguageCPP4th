/*
 * Ivaldial.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivaldial.h"
#include <iostream>
using namespace std;

Ival_dial::Ival_dial(int ll, int hh)
	: Ival_box{ll,hh}
{
}

int Ival_dial::get_value()
{
	return Ival_box::get_value();
}

void Ival_dial::prompt()
{
	cout << "enter value into Ival_dial: " << flush ;

	int v;
	cin >> v;
	Ival_box::set_value(v);
}


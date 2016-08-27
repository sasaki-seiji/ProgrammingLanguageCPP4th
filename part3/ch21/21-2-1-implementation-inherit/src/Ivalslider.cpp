/*
 * Ivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivalslider.h"
#include <iostream>
using namespace std;

Ival_slider::Ival_slider(int ll,int hh)
	: Ival_box{ll, hh}
{
}

int Ival_slider::get_value()
{
	return Ival_box::get_value();
}

void Ival_slider::prompt()
{
	cout << "enter value into Ival_slider: " << flush ;

	int v;
	cin >> v;
	Ival_box::set_value(v);
}


/*
 * Flashingivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Flashingivalslider.h"
#include <iostream>
using namespace std;

void Flashing_ival_slider::prompt()
{
	cout << "enter value into Flashing_ival_slider: " << flush ;

	int v;
	cin >> v;
	set_value(v);
}

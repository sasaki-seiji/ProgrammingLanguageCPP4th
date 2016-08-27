/*
 * Popupivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Popupivalslider.h"
#include <iostream>
using namespace std;

void Popup_ival_slider::prompt()
{
	cout << "enter value into Popup_ival_slider: " << flush ;

	int v;
	cin >> v;
	set_value(v);
}


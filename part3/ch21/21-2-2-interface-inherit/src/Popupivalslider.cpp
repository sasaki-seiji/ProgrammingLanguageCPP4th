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
	cout << "Popup_ival_slider: down/down/up/up" << endl ;

	on_down();
	on_down();
	on_up();
	on_up();
}


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
	cout << "Flashing_ival_slider: up/up/up/down" << endl ;

	on_up();
	on_up();
	on_up();
	on_down();
}

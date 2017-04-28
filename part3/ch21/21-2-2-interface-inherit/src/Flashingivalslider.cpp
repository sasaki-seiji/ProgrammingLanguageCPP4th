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
	cout << "Flashing_ival_slider: hit(20,5)/hit(75,4)" << endl ;

	on_mouse1hit(20,5);
	on_mouse1hit(75,4);
}

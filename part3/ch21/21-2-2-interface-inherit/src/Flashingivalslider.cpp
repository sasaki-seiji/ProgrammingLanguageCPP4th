/*
 * Flashingivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Flashingivalslider.h"
#include <iostream>
using namespace std;

Flashing_ival_slider::Flashing_ival_slider(int low, int high, int l, int t, int w, int h)
	:Ival_slider(low,high,l,t,w,h)
{
}

void Flashing_ival_slider::prompt()
{
	cout << "Flashing_ival_slider::prompt()\n" ;
}

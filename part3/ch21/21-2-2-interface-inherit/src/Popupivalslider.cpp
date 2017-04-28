/*
 * Popupivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Popupivalslider.h"
#include <iostream>
using namespace std;

Popup_ival_slider::Popup_ival_slider(int low, int high, int t, int l, int w, int h)
	: Ival_slider{low,high,t,l,w,h}
{
}

void Popup_ival_slider::prompt()
{
	cout << "Popup_ival_slider: hit(20,10)/hit(50,15)" << endl ;

	on_mouse1hit(20,10);
	on_mouse1hit(50,15);
}


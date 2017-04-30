/*
 * Popupivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Popupivalslider.h"
#include <iostream>
using namespace std;

Popup_ival_slider::Popup_ival_slider(int low, int high, int l, int t, int w, int h)
	: Ival_slider{low,high,l,t,w,h}
{
}

void Popup_ival_slider::prompt()
{
	cout << "Popup_ival_slider::prompt()\n" ;
}


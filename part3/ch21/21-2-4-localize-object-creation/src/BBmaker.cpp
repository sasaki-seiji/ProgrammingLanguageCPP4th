/*
 * BBmaker.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBmaker.h"
#include "BBpopupivalslider.h"
#include "BBivaldial.h"

Ival_dial* BB_maker::dial(int a, int b)
{
	return new BB_ival_dial(a,b);
}

Popup_ival_slider* BB_maker::popup_ival_slider(int a, int b)
{
	return new BB_popup_ival_slider(a,b);
}

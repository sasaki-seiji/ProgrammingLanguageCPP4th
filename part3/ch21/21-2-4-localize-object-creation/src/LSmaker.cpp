/*
 * LSmaker.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "LSmaker.h"
#include "LSivaldial.h"
#include "LSpopupivalslider.h"

Ival_dial* LS_maker::dial(int a, int b)
{
	return new LS_ival_dial(a,b);
}
Popup_ival_slider* LS_maker::popup_ival_slider(int a, int b)
{
	return new LS_popup_ival_slider(a,b);
}

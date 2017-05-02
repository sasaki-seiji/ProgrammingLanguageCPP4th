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
	: Ival_slider{low,high,l,t,w,h,false} // invisible initially
{
}

void Popup_ival_slider::prompt()
{
	cout << "Popup_ival_slider::prompt()\n" ;
}

void Popup_ival_slider::display_info() const
{
	cout << boolalpha;
	cout << "Popup_ival_slider(left=" << left() << ",top=" << top()
			<< ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible() << endl;
	cout << "  value=" << val << ",changed=" << changed << endl;
}

void Popup_ival_slider::popup()
{
	Window_manager* mgr = Window_manager::get_instance();
	mgr->bring_top(this);
	show();
}

void Popup_ival_slider::popdown()
{
	hide();
}

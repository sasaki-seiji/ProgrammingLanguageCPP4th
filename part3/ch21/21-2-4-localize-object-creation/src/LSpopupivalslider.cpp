/*
 * LSpopupivalslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "LSpopupivalslider.h"
#include <iostream>
using namespace std;

LS_popup_ival_slider::LS_popup_ival_slider(int low, int high, int l, int t, int w, int h)
	: LSslider{low,high,l,t,w,h,false}, changed{false}
{
}

int LS_popup_ival_slider::get_value()
{
	int val = value();
	changed = false;
	return val;
}

void LS_popup_ival_slider::set_value(int i)
{
	if (low() <= i && i <= high()) {
		value(i);
		changed = true;
	}
}

void LS_popup_ival_slider::reset_value(int i)
{
	if (low() <= i && i <= high()) {
		value(i);
		changed = false;
	}
}

void LS_popup_ival_slider::prompt()
{
	cout << "LS_popup_ival_slider::prompt()\n";
}

bool LS_popup_ival_slider::was_changed() const
{
	return changed;
}

void LS_popup_ival_slider::incr()
{
	if (value() < high()) {
		value(value()+1);
		changed = true;
	}
}

void LS_popup_ival_slider::decr()
{
	if (low() < value()) {
		value(value()-1);
		changed = true;
	}
}


void LS_popup_ival_slider::on_changed(int i)
{
	set_value(i);
}

void LS_popup_ival_slider::popup()
{
	Window_manager* mgr = Window_manager::get_instance();
	mgr->bring_top(this);
	show();
}

void LS_popup_ival_slider::popdown()
{
	hide();
}

void LS_popup_ival_slider::display_info() const
{
	cout << boolalpha;
	cout << "LS_popup_ival_slider: left=" << left()
			<< ",top=" << top() << ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible()
			<< ",value=" << value() << ",changed=" << changed << endl;

}

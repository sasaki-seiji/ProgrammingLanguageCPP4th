/*
 * BBpopupivalslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBpopupivalslider.h"
#include <iostream>
using namespace std;

BB_popup_ival_slider::BB_popup_ival_slider(int low, int high, int l, int t, int w, int h)
	: BBslider{low,high,l,t,w,h,false}, changed{false}
{
}

int BB_popup_ival_slider::get_value()
{
	int val = BBslider::value();
	changed = false;
	return val;
}

void BB_popup_ival_slider::set_value(int i)
{
	BBslider::value(i);
	changed = true;
}

void BB_popup_ival_slider::reset_value(int i)
{
	BBslider::value(i);
	changed = false;
}

void BB_popup_ival_slider::prompt()
{
	cout << "BB_popup_ival_slider::prompt()\n";
}

bool BB_popup_ival_slider::was_changed() const
{
	return changed;
}

void BB_popup_ival_slider::incr()
{
	if (value() < get_high()) {
		value(value()+1);
		changed = true;
	}
}

void BB_popup_ival_slider::decr()
{
	if (get_low() < value()) {
		value(value()-1);
		changed = true;
	}
}


void BB_popup_ival_slider::on_changed(int i)
{
	set_value(i);
}

void BB_popup_ival_slider::popup()
{
	Window_manager* mgr = Window_manager::get_instance();
	mgr->bring_top(this);
	show();
}

void BB_popup_ival_slider::popdown()
{
	hide();
}

void BB_popup_ival_slider::display_info() const
{
	cout << boolalpha;
	cout << "BB_popup_ival_slider(left=" << left()
			<< ",top=" << top() << ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible() << endl;
	cout << "  value=" << BBslider::value()
			<< ",changed=" << changed << endl;

}

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
	: BBslider{low,high,l,t,w,h}, changed{false}
{
}

int BB_popup_ival_slider::get_value()
{
	return BBslider::value();
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
	BBslider::value(BBslider::value()+1);
	changed = true;
}

void BB_popup_ival_slider::decr()
{
	BBslider::value(BBslider::value()-1);
	changed = true;
}


void BB_popup_ival_slider::on_changed(int i)
{
	set_value(i);
}

void BB_popup_ival_slider::popup()
{
	cout << "BB_popup_ival_slider::popup()\n";
}

void BB_popup_ival_slider::popdown()
{
	cout << "BB_popup_ival_slider::popdown()\n";
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

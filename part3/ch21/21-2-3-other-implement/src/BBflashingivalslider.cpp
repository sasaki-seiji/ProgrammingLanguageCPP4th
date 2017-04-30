/*
 * BBflashingivalslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBflashingivalslider.h"
#include <iostream>
using namespace std;

BB_flashing_ival_slider::BB_flashing_ival_slider(int low, int high, int l, int t, int w, int h)
	: BBwidget_with_bells_and_whistles{low, high, l, t, w, h}
		, changed{false}
{
}

int BB_flashing_ival_slider::get_value()
{
	int val = BBwidget_with_bells_and_whistles::value();
	changed = true;
	return val;
}

void BB_flashing_ival_slider::set_value(int i)
{
	BBwidget_with_bells_and_whistles::value(i);
	changed = true;
}

void BB_flashing_ival_slider::reset_value(int i)
{
	BBwidget_with_bells_and_whistles::value(i);
	changed = false;
}

void BB_flashing_ival_slider::prompt()
{
	cout << "BB_flashing_ival_slider::prompt()\n";
}

bool BB_flashing_ival_slider::was_changed() const
{
	return changed;
}

void BB_flashing_ival_slider::incr()
{
	int val = BBwidget_with_bells_and_whistles::value();
	BBwidget_with_bells_and_whistles::value(val+1);
}

void BB_flashing_ival_slider::decr()
{
	int val = BBwidget_with_bells_and_whistles::value();
	BBwidget_with_bells_and_whistles::value(val-1);
}

void BB_flashing_ival_slider::on_changed(int i)
{
	set_value(i);
}

void BB_flashing_ival_slider::flash()
{
	BBwidget_with_bells_and_whistles::flash();
}

void BB_flashing_ival_slider::display_info() const
{
	cout << boolalpha;
	cout << "BB_flashing_ival_slider(left=" << left()
			<< ",top=" << top() << ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible() << endl;
	cout << "  value=" << BBwidget_with_bells_and_whistles::value()
			<< ",changed=" << changed << endl;

}

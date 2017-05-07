/*
 * BBivaldial.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBivaldial.h"
#include <iostream>
using namespace std;

BB_ival_dial::BB_ival_dial(int low, int high, int l, int t, int w, int h)
	: BBdial{low,high,l,t,w,h}, changed{false}
{
}

int BB_ival_dial::get_value()
{
	int val = value();
	changed = false;
	return val;
}

void BB_ival_dial::set_value(int i)
{
	if (low() <= i && i <= high()) {
		changed = true;
		value(i);
	}
}

void BB_ival_dial::reset_value(int i)
{
	if (low() <= i && i <= high()) {
		changed = false;
		value(i);
	}
}

void BB_ival_dial::prompt()
{
	cout << "BB_ival_dial::prompt()\n";
}

bool BB_ival_dial::was_changed() const
{
	return changed;
}

void BB_ival_dial::turn_right()
{
	if (value() < high()) {
		value(value()+1);
		changed = true;
	}
}

void BB_ival_dial::turn_left()
{
	if (low() < value()) {
		value(value()-1);
		changed = true;
	}
}

void BB_ival_dial::on_changed(int i)
{
	set_value(i);
}

void BB_ival_dial::display_info() const
{
	cout << boolalpha;
	cout << "BB_ival_dial: left=" << left() << ",top=" << top()
			<< ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible()
			<< ",value=" << value() << ",changed=" << changed << endl;
}

/*
 * LSivaldial.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "LSivaldial.h"
#include <iostream>
using namespace std;

LS_ival_dial::LS_ival_dial(int low, int high, int l, int t, int w, int h)
	: LSdial{low,high,l,t,w,h}, changed{false}
{
}

int LS_ival_dial::get_value()
{
	int val = value();
	changed = false;
	return val;
}

void LS_ival_dial::set_value(int i)
{
	if (low() <= i && i <= high()) {
		changed = true;
		value(i);
	}
}

void LS_ival_dial::reset_value(int i)
{
	if (low() <= i && i <= high()) {
		changed = false;
		value(i);
	}
}

void LS_ival_dial::prompt()
{
	cout << "LS_ival_dial::prompt()\n";
}

bool LS_ival_dial::was_changed() const
{
	return changed;
}

void LS_ival_dial::turn_right()
{
	if (value() < high()) {
		value(value()+1);
		changed = true;
	}
}

void LS_ival_dial::turn_left()
{
	if (low() < value()) {
		value(value()-1);
		changed = true;
	}
}

void LS_ival_dial::on_changed(int i)
{
	set_value(i);
}

void LS_ival_dial::display_info() const
{
	cout << boolalpha;
	cout << "LS_ival_dial: left=" << left() << ",top=" << top()
			<< ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible()
			<< ",value=" << value() << ",changed=" << changed << endl;
}


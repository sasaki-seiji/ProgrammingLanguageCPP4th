/*
 * CWivalslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "CWivalslider.h"
#include <iostream>
using namespace std;

CW_ival_slider::CW_ival_slider(int low, int high, int l, int t, int w, int h)
	: CWslider{low,high,l,t,w,h}, changed{false}
{
}

int CW_ival_slider::get_value()
{
	int val = CWslider::value();
	changed = false;
	return val;
}

void CW_ival_slider::set_value(int i)
{
	CWslider::value(i);
	changed = true;
}

void CW_ival_slider::reset_value(int i)
{
	CWslider::value(i);
	changed = false;
}

void CW_ival_slider::prompt()
{
	cout << "CW_ival_slider::prompt()\n";
}

bool CW_ival_slider::was_changed() const
{
	return changed;
}

void CW_ival_slider::incr()
{
	if (value() < high()) {
		value(value()+1);
		changed = true;
	}
}

void CW_ival_slider::decr()
{
	if (low() < value()) {
		value(value()-1);
		changed = true;
	}
}

void CW_ival_slider::on_updated(int i)
{
	set_value(i);
}

void CW_ival_slider::display_info() const
{
	cout << boolalpha;
	cout << "CW_ival_slider(left=" << left() << ",top=" << top()
			<< ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible() << endl;
	cout << "  value=" << CWslider::value()
			<< ",changed=" << changed << endl;
}

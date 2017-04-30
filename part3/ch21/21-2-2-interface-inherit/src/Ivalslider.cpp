/*
 * Ivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivalslider.h"
#include <iostream>
using namespace std;

Ival_slider::Ival_slider(int low,int high, int l, int t, int w, int h)
	: BBwidget{l,t,w,h},
	  val{low}, low{low}, high{high}
{
}

Ival_slider::~Ival_slider()
{
}

int Ival_slider::get_value()
{
	changed = false;
	return val;
}

void Ival_slider::set_value(int i)
{
	if (i < low || high < i ) return;

	changed = true;
	val = i;
}

void Ival_slider::reset_value(int i)
{
	changed = false;
	val = i;
}

void Ival_slider::incr()
{
	if (val < high) {
		changed = true;
		val++;
	}
}

void Ival_slider::decr()
{
	if (low < val) {
		changed = true;
		val--;
	}
}

void Ival_slider::prompt()
{
	cout << "Ival_slider:prompt()\n";
}

bool Ival_slider::was_changed() const
{
	return changed;
}

void Ival_slider::on_mouse1hit(int x, int y)
{
	cout << "Ival_slider::on_mouse1hit(" << x << "," << y << ")\n";

	double xx = (double)x / width();
	int new_val = xx * (high-low) + low;
	set_value(new_val);
}

void Ival_slider::display_info() const
{
	cout << boolalpha;
	cout << "Ival_slider(left=" << left() << ",top=" << top()
			<< ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible() << endl;
	cout << "  value=" << val << ",changed=" << changed << endl;
}

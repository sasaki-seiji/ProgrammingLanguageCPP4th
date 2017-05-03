/*
 * Ivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivalslider.h"
#include <iostream>
using namespace std;

Ival_slider::Ival_slider(int ll,int hh,int l, int t, int w, int h)
	: Ival_box{ll, hh, l, t, w, h}
{
}

int Ival_slider::get_value()
{
	return Ival_box::get_value();
}

void Ival_slider::prompt()
{
	cout << "Ival_slider::prompt()\n" ;
}

void Ival_slider::display_info() const
{
	cout << "Ival_slider::";
	Ival_box::display_info();
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

void Ival_slider::on_mouse1hit(int x, int y)
{
	cout << "Ival_slider::on_mouse1hit(" << x << "," << y << ")\n";

	double xx = (double)x / width();
	int new_val = xx * (high-low) + low;
	set_value(new_val);
}

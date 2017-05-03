/*
 * Ivaldial.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivaldial.h"
#include <cmath>
#include <iostream>
using namespace std;

Ival_dial::Ival_dial(int ll, int hh, int l, int t, int w, int h)
	: Ival_box{ll,hh,l,t,w,h}
{
}

int Ival_dial::get_value()
{
	return Ival_box::get_value();
}

void Ival_dial::prompt()
{
	cout << "Ival_dial::prompt()\n" ;
}

void Ival_dial::display_info() const
{
	cout << "Ival_dial::";
	Ival_box::display_info();
}

void Ival_dial::turn_left()
{
	if (low < val) {
		changed = true;
		val--;
	}
}

void Ival_dial::turn_right()
{
	if (val < high) {
		changed = true;
		val++;
	}
}

void Ival_dial::on_mouse1hit(int x, int y)
{
	cout << "Ival_dial::on_mouse1hit(" << x << "," << y << ")\n";
	int center_x = width() / 2;
	int center_y = height();
	int yy = center_y - y;
	int xx = center_x - x;
	double xxx = xx / sqrt(xx*xx+yy*yy);
	double theta = acos(xxx);
	int new_val = static_cast<int>(theta / M_PI * (high-low) + low);

	set_value(new_val);
}

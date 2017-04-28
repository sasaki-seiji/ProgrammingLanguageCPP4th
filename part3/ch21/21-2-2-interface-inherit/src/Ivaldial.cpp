/*
 * Ivaldial.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivaldial.h"
#include <iostream>
#include <cmath>
using namespace std;

Ival_dial::	Ival_dial(int low, int high, int t, int l, int w, int h)
	: BBwidget{t,l,(w?w:default_width),(h?h:default_height)},
	  low{low}, high{high}, val{low}
{
}

Ival_dial::~Ival_dial()
{
}

int Ival_dial::get_value()
{
	changed = false;
	return val;
}

void Ival_dial::set_value(int i)
{
	changed = true;
	val = i;
}

void Ival_dial::reset_value(int i)
{
	changed = false;
	val = i;
}

void Ival_dial::prompt()
{
	cout << "Ival_dial: hit(40,40)/hit(50,10)" << endl;

	on_mouse1hit(40,40);
	on_mouse1hit(50,10);
}

bool Ival_dial::was_changed() const
{
	return changed;
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


/*
 * BBdial.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBdial.h"
#include <cmath>
#include <iostream>
using namespace std;

BBdial::BBdial(int low, int high, int l, int t, int w, int h, bool visible)
	:BBwidget{l,t,w,h,visible}, val{low}, lo{low}, hi{high}
{
}

void BBdial::on_mouse1hit(int x, int y)
{
	cout << "BBdial::on_mouse1hit(" << x << "," << y << ")\n";
	int center_x = width() / 2;
	int center_y = height();
	int yy = center_y - y;
	int xx = center_x - x;
	double xxx = xx / sqrt(xx*xx+yy*yy);
	double theta = acos(xxx);
	int new_val = static_cast<int>(theta / M_PI * (hi-lo) + lo);

	if (lo <= new_val && new_val <= hi) {
		val = new_val;
		on_changed(val);
	}
}

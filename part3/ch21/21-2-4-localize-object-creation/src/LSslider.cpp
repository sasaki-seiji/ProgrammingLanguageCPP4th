/*
 * LSslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "LSslider.h"
#include <iostream>
using namespace std;


LSslider::LSslider(int low, int high, int l, int t, int w, int h, bool visible)
	:LSwidget{l,t,w,h,visible}, val{low}, lo{low}, hi{high}
{
}

void LSslider::on_mouse1hit(int x, int y)
{
	cout << "LSslider::on_mouse1hit(" << x << "," << y << ")\n";

	double xx = (double)x / width();
	int new_val = xx * (hi-lo) + lo;
	if (lo <= new_val && new_val <= hi) {
		val = new_val;
		on_changed(val);
	}
}

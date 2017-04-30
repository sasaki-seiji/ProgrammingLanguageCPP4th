/*
 * BBslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBslider.h"
#include <iostream>
using namespace std;

BBslider::BBslider(int low, int high, int l, int t, int w, int h)
	:BBwidget{l,t,w,h}, val{low}, low{low}, high{high}
{
}

void BBslider::on_mouse1hit(int x, int y)
{
	cout << "BBslider::on_mouse1hit(" << x << "," << y << ")\n";

	double xx = (double)x / width();
	int new_val = xx * (high-low) + low;
	if (low <= new_val && new_val <= high) {
		val = new_val;
		on_changed(val);
	}
}

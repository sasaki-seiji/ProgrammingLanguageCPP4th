/*
 * CWslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "CWslider.h"
#include <iostream>
using namespace std;

CWslider::CWslider(int low, int high, int l, int t, int w, int h)
	: CWwidget{l,t,w,h}, val{low}, lo{low}, hi{high}
{
}

void CWslider::on_mouse1hit(int x, int y)
{
	cout << "CWslider::on_mouse1hit(" << x << "," << y << ")\n";

	double xx = (double)x / width();
	int new_val = xx * (hi-lo) + lo;
	if (lo <= new_val && new_val <= hi) {
		val = new_val;
		on_updated(val);
	}
}



/*
 * BBwidgetwithbellsandwhistles.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBwidgetwithbellsandwhistles.h"
#include <iostream>
using namespace std;

BBwidget_with_bells_and_whistles::BBwidget_with_bells_and_whistles(int low, int high, int l, int t, int w, int h)
	: BBslider{low,high,l,t,w,h}
{
}

void BBwidget_with_bells_and_whistles::flash()
{
	cout << "BBwidget_with_bells_and_whistles::flash()\n";
}


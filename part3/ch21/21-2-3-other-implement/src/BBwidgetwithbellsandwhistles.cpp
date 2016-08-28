/*
 * BBwidgetwithbellsandwhistles.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBwidgetwithbellsandwhistles.h"
#include <iostream>
using namespace std;

BBwidget_with_bells_and_whistles::BBwidget_with_bells_and_whistles(int ll, int hh)
	: BBslider{ll,hh}
{
}

void BBwidget_with_bells_and_whistles::prompt(const char* name)
{
	flash();
	BBslider::prompt(name);
}

void BBwidget_with_bells_and_whistles::flash()
{
	cout << "BBwidget_with_bells_and_whistles::flash()\n";
}


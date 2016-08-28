/*
 * BBpopupivalslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBpopupivalslider.h"
#include <iostream>
using namespace std;

BB_popup_ival_slider::BB_popup_ival_slider(int ll, int hh)
	: BBslider{ll,hh}
{
}

int BB_popup_ival_slider::get_value()
{
	return BBslider::value();
}

void BB_popup_ival_slider::set_value(int i)
{
	BBslider::value(i);
}

void BB_popup_ival_slider::reset_value(int i)
{
	BBslider::reset(i);
}

void BB_popup_ival_slider::prompt()
{
	BBslider::prompt("BB_popup_ival_slider");
}

bool BB_popup_ival_slider::was_changed() const
{
	return BBslider::was_changed();
}

void BB_popup_ival_slider::up()
{
	BBslider::incr();
}

void BB_popup_ival_slider::down()
{
	BBslider::decr();
}

void BB_popup_ival_slider::popup()
{
	cout << "BB_popup_ival_slider::popup()\n";
}

void BB_popup_ival_slider::popdown()
{
	cout << "BB_popup_ival_slider::popdown()\n";
}


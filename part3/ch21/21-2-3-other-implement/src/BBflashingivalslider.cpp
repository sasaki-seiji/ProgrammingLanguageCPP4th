/*
 * BBflashingivalslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBflashingivalslider.h"

BB_flashing_ival_slider::BB_flashing_ival_slider(int ll, int hh)
	: BBwidget_with_bells_and_whistles{ll,hh}
{
}

int BB_flashing_ival_slider::get_value()
{
	return BBwidget_with_bells_and_whistles::value();
}

void BB_flashing_ival_slider::set_value(int i)
{
	BBwidget_with_bells_and_whistles::value(i);
}

void BB_flashing_ival_slider::reset_value(int i)
{
	BBwidget_with_bells_and_whistles::reset(i);
}

void BB_flashing_ival_slider::prompt()
{
	BBwidget_with_bells_and_whistles::prompt("BB_flashing_ival_slider");
}

bool BB_flashing_ival_slider::was_changed() const
{
	return BBwidget_with_bells_and_whistles::was_changed();
}

void BB_flashing_ival_slider::up()
{
	BBwidget_with_bells_and_whistles::incr();
}

void BB_flashing_ival_slider::down()
{
	BBwidget_with_bells_and_whistles::decr();
}

void BB_flashing_ival_slider::flash()
{
	BBwidget_with_bells_and_whistles::flash();
}

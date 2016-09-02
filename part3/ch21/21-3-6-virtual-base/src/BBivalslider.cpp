/*
 * BBivalslider.cpp
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#include "BBivalslider.h"
#include <iostream>
using namespace std;

int BB_ival_slider::get_value()
{
	return BBslider::value();
}

void BB_ival_slider::set_value(int i)
{
	BBslider::value(i);
}

void BB_ival_slider::reset_value(int i)
{
	BBslider::reset(i);
}

void BB_ival_slider::prompt()
{
	BBslider::prompt("BB_ival_slider");
}


bool BB_ival_slider::was_changed() const
{
	return BBslider::was_changed();
}

void BB_ival_slider::up()
{
	BBslider::incr();
}

void BB_ival_slider::down()
{
	BBslider::decr();
}


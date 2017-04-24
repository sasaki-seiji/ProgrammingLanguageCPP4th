/*
 * Ivalslider.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivalslider.h"
#include <iostream>
using namespace std;

Ival_slider::Ival_slider(int ll,int hh)
	: val{ll}, low{ll}, high{hh}
{
}

Ival_slider::~Ival_slider()
{
}

int Ival_slider::get_value()
{
	changed = false;
	return val;
}

void Ival_slider::set_value(int i)
{
	if (i < low || high < i ) return;

	changed = true;
	val = i;
}

void Ival_slider::reset_value(int i)
{
	changed = false;
	val = i;
}

void Ival_slider::prompt()
{
	cout << "Ival_slider: up/up/down/up" << endl;

	on_up();
	on_up();
	on_down();
	on_up();
}

bool Ival_slider::was_changed() const
{
	return changed;
}

void Ival_slider::on_up()
{
	int i = get_value();
	set_value(i+1);
}

void Ival_slider::on_down()
{
	int i = get_value();
	set_value(i-1);
}


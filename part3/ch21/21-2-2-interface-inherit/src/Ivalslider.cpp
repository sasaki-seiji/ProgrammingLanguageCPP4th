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
	cout << "enter value into Ival_slider: " << flush ;

	int v;
	cin >> v;
	set_value(v);
}

bool Ival_slider::was_changed() const
{
	return changed;
}


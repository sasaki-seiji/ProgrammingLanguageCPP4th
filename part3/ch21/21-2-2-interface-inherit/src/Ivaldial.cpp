/*
 * Ivaldial.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivaldial.h"
#include <iostream>
using namespace std;

Ival_dial::Ival_dial(int ll, int hh)
	: val{ll}, low{ll}, high{hh}
{
}

Ival_dial::~Ival_dial()
{
}

int Ival_dial::get_value()
{
	changed = false;
	return val;
}

void Ival_dial::set_value(int i)
{
	changed = true;
	val = i;
}

void Ival_dial::reset_value(int i)
{
	changed = false;
	val = i;
}

void Ival_dial::prompt()
{
	cout << "enter value into Ival_dial: " << flush ;

	int v;
	cin >> v;
	set_value(v);
}

bool Ival_dial::was_changed() const
{
	return changed;
}


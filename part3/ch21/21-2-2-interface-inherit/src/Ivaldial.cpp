/*
 * Ivaldial.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Ivaldial.h"
#include <iostream>
using namespace std;

Ival_dial::Ival_dial(int init)
	: val{init}
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
	cout << "Ival_dial: down/down/up/down" << endl;

	on_down();
	on_down();
	on_up();
	on_down();
}

bool Ival_dial::was_changed() const
{
	return changed;
}

void Ival_dial::on_up()
{
	int i = get_value();
	set_value(i+1);
}

void Ival_dial::on_down()
{
	int i = get_value();
	set_value(i-1);
}

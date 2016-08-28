/*
 * user.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */


#include "BBivalslider.h"
#include "BBflashingivalslider.h"
#include "BBpopupivalslider.h"
#include "CWivalslider.h"
#include <iostream>
#include <memory>
using namespace std;

void interact(Ival_box* pb)
{
	int old_val = pb->get_value();
	pb->prompt();

	int i = pb->get_value();
	if (i != old_val) {
		cout << "new value: " << i << '\n';
	}
	else {
		cout << "not changed. old value: " << old_val << '\n';
	}
}

void some_fct()
{
	unique_ptr<Ival_box> p1 { new BB_ival_slider{0,5} };
	interact(p1.get());
	unique_ptr<Ival_box> p2 { new BB_flashing_ival_slider{0,10} };
	interact(p2.get());
	unique_ptr<Ival_box> p3 { new BB_popup_ival_slider{0,10} };
	interact(p3.get());
	unique_ptr<Ival_box> p4 { new CW_ival_slider{0,10} };
	interact(p4.get());
}

void up_down(Ival_slider* ivs)
{
	cout << "original value: " << ivs->get_value() << '\n';
	ivs->up(); ivs->up();
	cout << "after up() twice, value: " << ivs->get_value() << '\n';
	ivs->down();
	cout << "after down(), value: " << ivs->get_value() << '\n';
}

void popup_down(Popup_ival_slider* pivs)
{
	pivs->popup();
	pivs->popdown();
}

// add main

int main()
{
	some_fct();

	unique_ptr<Ival_slider> p1 { new BB_ival_slider{0,5} };
	up_down(p1.get());

	unique_ptr<Ival_slider> p2 { new BB_flashing_ival_slider{0,5} };
	up_down(p2.get());

	unique_ptr<Popup_ival_slider> p3 { new BB_popup_ival_slider{0,5} };
	popup_down(p3.get());
}


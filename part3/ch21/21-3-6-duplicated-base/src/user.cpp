/*
 * user.cpp
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#include "BBpopupivalslider.h"
#include <memory>
#include <iostream>
using namespace std;

Popup_ival_slider* popup_slider_factory(int ll, int hh)
{
	return new BB_popup_ival_slider(ll, hh);
}

void interact(Ival_slider* pb)
{
	cout << "-- interact(Ival_slider*) --\n";

	bool changed;
	int i;

	pb->prompt();

	cout << "old value: " << pb->get_value() << endl;

	pb->set_value(5);
	changed = pb->was_changed();
	i = pb->get_value();
	cout << "after set_value(5): " << i << ", changed: " << changed << endl;
	cout << "after get_value(), changed: " << pb->was_changed() << endl;

	pb->set_value(2);
	pb->reset_value(7);
	changed = pb->was_changed();
	i = pb->get_value();
	cout << "set_value(2), reset_value(7): " << i << ", changed: " << changed << endl;
}


void incr_decr(Ival_slider* ivs)
{
	cout << "-- incr_decr(Ival_slider*) --\n";

	int v;
	bool changed;

	cout << boolalpha;

	ivs->prompt();
	changed = ivs->was_changed(); v = ivs->get_value();
	cout << "original value: " << v << ", changed: " << changed <<  endl;

	ivs->decr();
	changed = ivs->was_changed(); v = ivs->get_value();
	cout << "after decr(), value: " << v << ", changed: " << changed << endl;

	ivs->incr(); ivs->incr();
	changed = ivs->was_changed(); v = ivs->get_value();
	cout << "after incr() twice, value: " << v << ", changed: " << changed << endl;

	ivs->decr();
	changed = ivs->was_changed(); v = ivs->get_value();
	cout << "after decr(), value: " << v << ", changed: " << changed << endl;
}

void popup_down(Popup_ival_slider* pivs)
{
	cout << "-- popup_down(Popup_ival_slider*) --\n";

	cout << "- original state -\n";
	pivs->display_info();

	Window_manager* mgr = Window_manager::get_instance();

	cout << "mouse1hit: (60,60)\n";
	mgr->mouse1hit(60,60);

	cout << "- after hittest -\n";
	pivs->display_info();

	cout << "popup(), mouse1hit: (70,70)\n";
	pivs->popup();
	mgr->mouse1hit(70,70);

	cout << "- after hittest -\n";
	pivs->display_info();

	cout << "popdown(), mouse1hit: (80,80)\n";
	pivs->popdown();
	mgr->mouse1hit(80,80);

	cout << "- after hittest -\n";
	pivs->display_info();
}

// add main

int main()
{
	cout << "sizeof(BB_popup_ival_slider): " << sizeof(BB_popup_ival_slider) << '\n';

	Popup_ival_slider *pivs = popup_slider_factory(0,99);
	interact(pivs);
	incr_decr(pivs);
	popup_down(pivs);
}


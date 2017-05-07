/*
 * user.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "WinMgr.h"
#include "Ivalmaker.h"
#include "Ivalbox.h"
#include "Ivalslider.h"
#include "Ivaldial.h"
#include "Popupivalslider.h"
#include <memory>
#include <iostream>
using namespace std;

void interact(Ival_box* pb)
{
	cout << "-- interact() --\n";

	bool changed;
	int i;

	pb->prompt();

	cout << "old value: " << pb->get_value() << endl;

	pb->set_value(5);
	changed = pb->was_changed();
	i = pb->get_value();
	cout << "after set_value(5): " << i << ", changed: " << changed << endl;
	cout << "after get_value(), changed: " << pb->was_changed() << endl;

	pb->set_value(-1);
	changed = pb->was_changed();
	i = pb->get_value();
	cout << "after set_value(-1): " << i << ", changed: " << changed << endl;

	pb->reset_value(7);
	changed = pb->was_changed();
	i = pb->get_value();
	cout << "set_reset_value(7): " << i << ", changed: " << changed << endl;
}

void dial_test(Ival_dial* ivd)
{
	cout << "-- dial_test() --\n";

	bool changed;
	int i;
	cout << boolalpha;

	cout << "- initial state --\n";
	ivd->display_info();

	ivd->turn_left();
	changed = ivd->was_changed();
	i = ivd->get_value();
	cout << "after turn_left(), value: " << i << ", changed: " << changed << endl;

	ivd->turn_right(); ivd->turn_right();
	changed = ivd->was_changed();
	i = ivd->get_value();
	cout << "after turn_right() twice, value: " << i << ", changed: " << changed << endl;

	ivd->turn_left();
	changed = ivd->was_changed();
	i = ivd->get_value();
	cout << "after turn_left(), value: " << i << ", changed: " << changed << endl;

	cout << "- final state --\n";
	ivd->display_info();
}

void popup_test(Popup_ival_slider* pivs)
{
	cout << "-- popup_test() --\n";

	Window_manager *mgr = Window_manager::get_instance();

	cout << "- initail state -\n";
	pivs->display_info();

	mgr->mouse1hit(80, 80);
	cout << "- after mouse1hit(80,80) -\n";
	pivs->display_info();

	pivs->popup();
	mgr->mouse1hit(90, 90);
	cout << "- after popup(), mouse1hit(90,90) -\n";
	pivs->display_info();

	pivs->popdown();
	mgr->mouse1hit(100, 100);
	cout << "- after popdown(), mouse1hit(100,100) -\n";
	pivs->display_info();
}

void user(Ival_maker& im)
{
	unique_ptr<Ival_box> pd {im.dial(0,99)};
	interact(pd.get());
	unique_ptr<Ival_box> pp {im.popup_ival_slider(0,99)};
	interact(pp.get());

	dial_test(im.dial(0,99));
	popup_test(im.popup_ival_slider(0,99));
}


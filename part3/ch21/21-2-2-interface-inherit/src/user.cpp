/*
 * user.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */


#include "Ivalbox.h"
#include "Ivalslider.h"
#include "Ivaldial.h"
#include "Flashingivalslider.h"
#include "Popupivalslider.h"
#include <memory>
#include <iostream>
using namespace std;

void interact(Ival_box* pb)
{
	pb->prompt();

	cout << "old value: " << pb->get_value() << endl;

	pb->set_value(5);
	bool changed = pb->was_changed();
	int i = pb->get_value();
	cout << "new value: " << i << ", changed: " << changed << endl;

	pb->reset_value(7);
	changed = pb->was_changed();
	i = pb->get_value();
	cout << "reset value: " << i << ", changed: " << changed << endl;
}

void some_fct()
{
	cout << "-- some_fct() --\n";

	unique_ptr<Ival_box> p1 { new Ival_slider{0,10} };
	interact(p1.get());
	unique_ptr<Ival_box> p2 { new Ival_dial{0, 10} };
	interact(p2.get());
	unique_ptr<Ival_box> p3 { new Flashing_ival_slider{0,10} };
	interact(p3.get());
	unique_ptr<Ival_box> p4 { new Popup_ival_slider{0,10} };
	interact(p4.get());
}

void incr_decr(Ival_slider* ivs)
{
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

void test_incr_decr()
{
	cout << "-- test_incr_decr() --" << endl;

	unique_ptr<Ival_slider> p1 { new Ival_slider{0, 10} };
	incr_decr(p1.get());

	unique_ptr<Ival_slider> p2 { new Flashing_ival_slider{0, 10} };
	incr_decr(p2.get());

	unique_ptr<Ival_slider> p3 { new Popup_ival_slider{0, 10} };
	incr_decr(p3.get());
}

void turn_left_right(Ival_dial* ivd)
{
	int v;
	bool changed;

	cout << boolalpha;

	ivd->prompt();
	changed = ivd->was_changed(); v = ivd->get_value();
	cout << "original value: " << v << ", changed: " << changed <<  endl;

	ivd->turn_left();
	changed = ivd->was_changed(); v = ivd->get_value();
	cout << "after turn_left(), value: " << v << ", changed: " << changed << endl;

	ivd->turn_right(); ivd->turn_right();
	changed = ivd->was_changed(); v = ivd->get_value();
	cout << "after turn_right() twice, value: " << v << ", changed: " << changed << endl;

	ivd->turn_left();
	changed = ivd->was_changed(); v = ivd->get_value();
	cout << "after turn_left(), value: " << v << ", changed: " << changed << endl;
}

void test_turn_left_right()
{
	cout << "-- test_turn_left_right() --" << endl;

	unique_ptr<Ival_dial> p1 { new Ival_dial{0, 10} };
	turn_left_right(p1.get());
}

void hittest()
{
	cout << "-- hittest() --\n";

	unique_ptr<Ival_box> p1 { new Ival_slider{0,10, 0, 0, 100, 20} };
	unique_ptr<Ival_box> p2 { new Flashing_ival_slider{0,10, 0, 20, 100, 20} };
	unique_ptr<Ival_box> p3 { new Popup_ival_slider{0,10, 0, 40, 100, 20} };
	unique_ptr<Ival_box> p4 { new Ival_dial{0,10, 100, 0, 100, 50} };

	cout << "- original state -\n";

	p1.get()->display_info();
	p2.get()->display_info();
	p3.get()->display_info();
	p4.get()->display_info();

	Window_manager* mgr = Window_manager::get_instance();

	cout << "mouse1hit: (80,10), (60, 30), (40, 50), (130, 20)\n";
	mgr->mouse1hit(80,10);
	mgr->mouse1hit(60,30);
	mgr->mouse1hit(40,50);
	mgr->mouse1hit(130,20);

	cout << "- after hittest -\n";

	p1.get()->display_info();
	p2.get()->display_info();
	p3.get()->display_info();
	p4.get()->display_info();
}

//  add main

int main()
{
	some_fct();
	test_incr_decr();
	test_turn_left_right();
	hittest();
}

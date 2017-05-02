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

void some_fct()
{
	cout << "-- some_fct() --\n";

	unique_ptr<Ival_box> p1 { new BB_ival_slider{0,10} };
	interact(p1.get());
	unique_ptr<Ival_box> p2 { new BB_flashing_ival_slider{0,10} };
	interact(p2.get());
	unique_ptr<Ival_box> p3 { new BB_popup_ival_slider{0,10} };
	interact(p3.get());
	unique_ptr<Ival_box> p4 { new CW_ival_slider{0,10} };
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

	unique_ptr<Ival_slider> p1 { new BB_ival_slider{0, 10} };
	incr_decr(p1.get());

	unique_ptr<Ival_slider> p2 { new BB_flashing_ival_slider{0, 10} };
	incr_decr(p2.get());

	unique_ptr<Ival_slider> p3 { new BB_popup_ival_slider{0, 10} };
	incr_decr(p3.get());

	unique_ptr<Ival_slider> p4 { new CW_ival_slider{0, 10} };
	incr_decr(p4.get());
}

void flash(Flashing_ival_slider* fivs)
{
	fivs->flash();
}

void test_flash()
{
	cout << "-- test_flash() --\n";

	unique_ptr<Flashing_ival_slider> p1 { new BB_flashing_ival_slider{0,10} };
	flash(p1.get());
}

void hittest()
{
	cout << "-- hittest() --\n";

	unique_ptr<Ival_box> p1 { new BB_ival_slider{0,10, 0, 0, 100, 20} };
	unique_ptr<Ival_box> p2 { new BB_flashing_ival_slider{0,10, 0, 20, 100, 20} };
	unique_ptr<Ival_box> p3 { new BB_popup_ival_slider{0,10, 0, 40, 100, 20} };
	unique_ptr<Ival_box> p4 { new CW_ival_slider{0,10, 100, 0, 100, 50} };

	cout << "- original state -\n";

	p1.get()->display_info();
	p2.get()->display_info();
	p3.get()->display_info();
	p4.get()->display_info();

	Window_manager* mgr = Window_manager::get_instance();

	cout << "mouse1hit: (80,10), (60, 30), (40, 50), (120, 30)\n";
	mgr->mouse1hit(80,10);
	mgr->mouse1hit(60,30);
	mgr->mouse1hit(40,50);
	mgr->mouse1hit(120,30);

	cout << "- after hittest -\n";

	p1.get()->display_info();
	p2.get()->display_info();
	p3.get()->display_info();
	p4.get()->display_info();
}

void test_popup_down()
{
	cout << "-- test_popup_down() --\n";

	unique_ptr<Popup_ival_slider> p1 { new BB_popup_ival_slider{0, 10, 0, 0, 100, 20} };

	cout << "- original state -\n";
	p1.get()->display_info();

	Window_manager* mgr = Window_manager::get_instance();

	cout << "mouse1hit: (30,10)\n";
	mgr->mouse1hit(30,10);

	cout << "- after hittest -\n";
	p1.get()->display_info();

	cout << "popup(), mouse1hit: (30,10)\n";
	p1.get()->popup();
	mgr->mouse1hit(30,10);

	cout << "- after hittest -\n";
	p1.get()->display_info();

	cout << "popdown(), mouse1hit: (70,10)\n";
	p1.get()->popdown();
	mgr->mouse1hit(70,10);

	cout << "- after hittest -\n";
	p1.get()->display_info();
}

// add main

int main()
{
	some_fct();
	test_incr_decr();
	test_flash();
	hittest();
	test_popup_down();
}


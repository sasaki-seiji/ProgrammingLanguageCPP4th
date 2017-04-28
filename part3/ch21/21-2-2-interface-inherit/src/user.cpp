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
	unique_ptr<Ival_box> p1 { new Ival_slider{0,100,100,50} };
	interact(p1.get());
	unique_ptr<Ival_box> p2 { new Ival_dial{0, 100, 100, 150} };
	interact(p2.get());
	unique_ptr<Ival_box> p3 { new Flashing_ival_slider{0,100, 200,50} };
	interact(p3.get());
	unique_ptr<Ival_box> p4 { new Popup_ival_slider{0,100, 200, 150} };
	interact(p4.get());
}

//  add main

int main()
{
	some_fct();
}

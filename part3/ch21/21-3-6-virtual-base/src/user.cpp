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

void interact(Ival_slider* pb)
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
	unique_ptr<Ival_slider> p3 { new BB_popup_ival_slider{0,10} };
	interact(p3.get());
}

void popup_test(Popup_ival_slider* pivs)
{
	pivs->popup();
	pivs->popdown();
}

// add main

int main()
{
	some_fct();

	Popup_ival_slider *pivs = new BB_popup_ival_slider{0,99};
	popup_test(pivs);

	cout << "sizeof(BB_popup_ival_slider): " << sizeof(BB_popup_ival_slider) << '\n';
}


/*
 * user.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */


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

void dial_test(Ival_dial* ivd)
{
	cout << "initially value: " << ivd->get_value() << '\n';
	ivd->right(20);
	cout << "after right(20), value: " << ivd->get_value() << '\n';
	ivd->left(10);
	cout << "after left(10), value: " << ivd->get_value() << '\n';
}

void popup_test(Popup_ival_slider* pivs)
{
	pivs->popup();
	pivs->popdown();
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


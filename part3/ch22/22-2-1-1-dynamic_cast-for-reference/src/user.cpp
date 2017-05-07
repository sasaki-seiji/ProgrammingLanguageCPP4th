/*
 * user.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#include "Ivalbox.h"
#include "Ivalslider.h"
#include "BBivalslider.h"
#include "BBivaldial.h"
#include <iostream>
#include <typeinfo>
using namespace std;

void fp(Ival_box* p)
{
	cout << "-- fp(Ival_box*) --\n";
	p->display_info();

	if (Ival_slider* is = dynamic_cast<Ival_slider*>(p)) {
		is->incr();
		p->display_info();
	}
	else {
		cout << "dynamic_cast<Ival_slider*> fails!\n";
	}
}

void fr(Ival_box& r)
{
	cout << "-- fr(Ival_box&) --\n";
	r.display_info();

	Ival_slider& is = dynamic_cast<Ival_slider&>(r);
	is.decr();

	r.display_info();
}

void g(BB_ival_slider& slider, BB_ival_dial& dial)
{
	cout << "-- g(BB_ival_slider&, BB_ival_dial&) --\n";

	try {
		fp(&slider);
		fr(slider);
		fp(&dial);
		fr(dial);
	}
	catch (const bad_cast& e) {
		cout << "bad_cast: " << e.what() << '\n';
	}
}

// add main

int main()
{
	BB_ival_slider slider{0,99};
	BB_ival_dial dial{0,99};
	g(slider, dial);
}



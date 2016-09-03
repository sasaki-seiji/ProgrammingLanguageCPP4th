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
	if (Ival_slider* is = dynamic_cast<Ival_slider*>(p)) {
		is->up();
		is->down();
	}
	else {
		cout << "dynamic_cast<Ival_slider*> fails!\n";
	}
}

void fr(Ival_box& r)
{
	Ival_slider& is = dynamic_cast<Ival_slider&>(r);
	is.up();
	is.down();
}

void g(BB_ival_slider& slider, BB_ival_dial& dial)
{
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



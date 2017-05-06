/*
 * user.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#include "BBivalslider.h"
#include "BBwindowsystem.h"
#include <memory>
#include <iostream>
using namespace std;

void my_event_handler(BBwidget* pw)
{
	if (auto pb = dynamic_cast<Ival_box*>(pw)) {
		int x = pb->get_value();
		cout << "value: " << x << '\n';
	}
	else {
		cout << "cannot cast to Ival_box!\n";
	}
}

int main()
{
	BB_window_system* winsys = BB_window_system::get_instance();

	BB_ival_slider slider{0,99};
	winsys->add_event_handler(&slider, my_event_handler);

	slider.set_value(10);
	winsys->fire_event();

	slider.set_value(99);
	winsys->fire_event();
}


/*
 * BBwindowsystem.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#include "BBwindowsystem.h"

BB_window_system* BB_window_system::get_instance()
{
	if (!instance)
		instance = new BB_window_system();
	return instance;
}

void BB_window_system::add_event_handler(BBwindow* w, Callback cb)
{
	handlers.push_back(pair<BBwindow*,Callback>(w,cb));
}

void BB_window_system::fire_event()
{
	for (auto x : handlers)
		(*x.second)(x.first);
}

BB_window_system* BB_window_system::instance = nullptr;

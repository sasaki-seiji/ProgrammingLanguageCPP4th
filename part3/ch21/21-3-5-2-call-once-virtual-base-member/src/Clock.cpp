/*
 * Clock.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include "Clock.h"
#include <iostream>
using namespace std;

void Clock::own_draw()
{
	cout << "Clock::own_draw()\n";
}

void Clock::draw()
{
	Window::draw();
	Window_with_border::own_draw();
	Window_with_menu::own_draw();
	own_draw();
}


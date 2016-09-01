/*
 * user.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include "Window.h"
#include "Clock.h"
#include <iostream>
using namespace std;

void f(Window* wp)
{
	wp->draw();
}

// add main

int main()
{
	cout << "Window instance:\n";
	Window win;
	f(&win);

	cout << "\nWindow_with_border instance:\n";
	Window_with_border wwb;
	f(&wwb);

	cout << "\nWindow_with_menu instance:\n";
	Window_with_menu wwm;
	f(&wwm);

	cout << "\nClock instance:\n";
	Clock clock;
	f(&clock);

}


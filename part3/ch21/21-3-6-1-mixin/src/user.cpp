/*
 * user.cpp
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#include "Mywindow.h"
#include <iostream>
using namespace std;

void f0(Window* w)
{
	cout << "-- f0(Window*) --\n";

	Color color{100,200,50};
	w->set_color(color);
	w->prompt();
}

void f1(Window_with_border* w)
{
	cout << "-- f1(Window_with_border*) --\n";

	Color color{100,200,50};
	w->set_color(color);
	w->prompt();
}

void f2(Window_with_menu* w)
{
	cout << "-- f2(Window_with_menu*) --\n";

	Color color{100,200,50};
	w->set_color(color);
	w->prompt();
}

void f3(My_window* w)
{
	cout << "-- f3(My_window*) --\n";

	Color color{100,200,50};
	w->set_color(color);
	w->prompt();
}

// add main

int main()
{
	My_window mywin;
	f0(&mywin);
	f1(&mywin);
	f2(&mywin);
	f3(&mywin);
}


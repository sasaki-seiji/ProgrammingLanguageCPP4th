/*
 * user.cpp
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#include "Commsat.h"
#include "Commsat2.h"
#include "Telstar2.h"
#include "Cowboywindow.h"
#include <iostream>
using namespace std;

void f(Comm_sat& cs)
{
	Debug_info di;
	//di = cs.get_debug();
		// error: request for member 'get_debug' is ambiguous
	di = cs.Satellite::get_debug();
	cout << "cs.Satellite::get_debug(): " << di << '\n';

	di = cs.Displayed::get_debug();
	cout << "cs.Displayed::get_debug(): " << di << '\n';
}

void f(Comm_sat2& cs2)
{
	Debug_info di;
	di = cs2.get_debug();
	cout << "cs2.get_debug(): " << di << '\n';
}

void g(Comm_sat2& cs2)
{
	cs2.draw();
}

void window(Window& w)
{
	w.draw();
}

void cowboy(Cowboy& c)
{
	c.draw();
}

// add main

int main()
{
	Comm_sat cs;
	f(cs);

	Comm_sat2 cs2;
	f(cs2);

	Telstar2 ts2;
	g(ts2);

	Cowboy_window cw;
	window(cw);
	cowboy(cw);
}

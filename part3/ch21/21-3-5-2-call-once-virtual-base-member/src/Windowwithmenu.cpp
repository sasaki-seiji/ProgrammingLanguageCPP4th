/*
 * Windowwithmenu.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include "Windowwithmenu.h"
#include <iostream>
using namespace std;

void Window_with_menu::own_draw()
{
	cout << "Window_with_menu::own_draw()\n";
}

void Window_with_menu::draw()
{
	Window::draw();
	own_draw();
}


/*
 * Windowwithborder.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include "Windowwithborder.h"
#include <iostream>
using namespace std;

void Window_with_border::own_draw()
{
	cout << "Window_with_border::own_draw()\n";
}

void Window_with_border::draw()
{
	Window::draw();
	own_draw();
}

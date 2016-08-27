/*
 * Window.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Window.h"
#include <iostream>
using namespace std;

void Window::start()
{
	cout << name << ".Window::start()\n";
}
void Window::suspend()
{
	cout << name << ".Window::suspend()\n";
}
void Window::resume()
{
	cout << name << ".Window::resume()\n";
}
void Window::quit()
{
	cout << name << ".Window::quit()\n";
}
void Window::full_size()
{
	cout << name << ".Window::full_size()\n";
}
void Window::small()
{
	cout << name << ".Window::small()\n";
}


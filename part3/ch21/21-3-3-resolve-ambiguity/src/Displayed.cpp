/*
 * Displayed.cpp
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#include "Displayed.h"
#include <iostream>
using namespace std;

Debug_info Displayed::get_debug()
{
	Debug_info info;
	info.push_back("displayed debug info");
	return info;
}

void Displayed::draw()
{
	cout << "Displayed::draw()\n";
}

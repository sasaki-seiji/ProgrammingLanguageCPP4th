/*
 * Displayed.cpp
 *
 *  Created on: 2016/08/29
 *      Author: sasaki
 */

#include "Displayed.h"
#include <iostream>
using namespace std;

void highlight(Displayed* d)
{
	cout << "highlight(Displayed*)\n";
	d->draw();
}


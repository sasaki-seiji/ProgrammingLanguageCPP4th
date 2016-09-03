/*
 * user1.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#include "Radio.h"
#include <iostream>
using namespace std;

void h1(Radio& r)
{
	Storable* ps = &r;
	cout << "ps (Storable* ps = &r): " << ps << '\n';

	Component* pc = dynamic_cast<Component*>(ps);
	cout << "dynamic_cast<Component*>(ps): " << pc << '\n';
}


/*
 * user2.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#include "Component.h"
#include <iostream>
#include <typeinfo>
using namespace std;

void h2(Storable* ps)
{
	cout << "-- h2(Storable* ps: " << ps << ")\n";
	cout << "typeid(*ps).name(): " << typeid(*ps).name() << endl;

	if (Component* pc = dynamic_cast<Component*>(ps)) {
		cout << "*ps has a Component: " << pc << endl;
	}
	else {
		cout << "*ps does not have a Component\n";
	}
}

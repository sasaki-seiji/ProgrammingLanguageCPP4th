/*
 * user2.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#include "Component.h"
#include <iostream>
using namespace std;

void h2(Storable* ps)
{
	if (Component* pc = dynamic_cast<Component*>(ps)) {
		cout << "*ps has a Component\n";
	}
	else {
		cout << "*ps does not have a Component\n";
	}
}

/*
 * list_container.cpp
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#include <stdexcept>
using namespace std;

#include "list_container.h"

double& List_container::operator[](int i)
{
	for (auto& x : ld) {
		if (i == 0) return x;
		--i;
	}
	throw out_of_range("List container");
}



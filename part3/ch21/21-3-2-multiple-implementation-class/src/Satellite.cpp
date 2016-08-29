/*
 * Satellite.cpp
 *
 *  Created on: 2016/08/29
 *      Author: sasaki
 */

#include "Satellite.h"
#include <iostream>
using namespace std;

Pos center_of_gravity(const Satellite* s)
{
	cout << "center_of_gravity(Sattellite*)\n";
	return s->center();
}


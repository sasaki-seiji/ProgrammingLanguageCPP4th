/*
 * Commsat.cpp
 *
 *  Created on: 2016/08/29
 *      Author: sasaki
 */

#include "Commsat.h"
#include <iostream>
using namespace std;

Pos Comm_sat::center() const
{
	return pos;
}

void Comm_sat::draw()
{
	cout << "Comm_sat::draw()\n";
}


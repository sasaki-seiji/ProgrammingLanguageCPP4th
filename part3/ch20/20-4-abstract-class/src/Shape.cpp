/*
 * Shape.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#include "Shape.h"

ostream& operator<<(ostream& os, Point pt)
{
	os << "(" << pt.x << "," << pt.y << ")";
	return os;
}


/*
 * Vector.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include "Vector.h"

Vector::Vector(int s)
{
	if (s<0) throw Bad_size{s};
	sz = s;
	elem = new double[s];
}

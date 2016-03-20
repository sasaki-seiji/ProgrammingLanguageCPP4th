/*
 * Vector.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */
#include "Vector.h"

Vector::Vector(int s)
	:elem{new double[s]}, sz{s}
{
}

double& Vector::operator[](int i)
{
	return elem[i];
}

int Vector::size()
{
	return sz;
}

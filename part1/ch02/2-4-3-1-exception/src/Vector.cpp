/*
 * Vector.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include <stdexcept>
using namespace std;

#include "Vector.h"

Vector::Vector(int s)
	:elem{new double[s]}, sz{s}
{
}

double& Vector::operator[](int i)
{
	if( i < 0 || size() <= i ) throw out_of_range("Vector::operator[]");
	return elem[i];
}

int Vector::size()
{
	return sz;
}

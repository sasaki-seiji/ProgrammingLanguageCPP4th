/*
 * Shape.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Shape.h"
#include <iostream>
using namespace std;

bool Circle::intersect(const Shape& s) const
{
	return s.intersect(*this);
}

bool Circle::intersect(const Circle&) const
{
	cout << "intersect(circle,circle)\n";
	return true;
}

bool Circle::intersect(const Triangle&) const
{
	cout << "intersect(triangle,circle)\n";
	return true;
}

bool Triangle::intersect(const Shape& s) const
{
	return s.intersect(*this);
}

bool Triangle::intersect(const Circle&) const
{
	cout << "intersect(circle,triangle)\n";
	return true;
}

bool Triangle::intersect(const Triangle&) const
{
	cout << "intersect(triangle,triangle)\n";
	return true;
}

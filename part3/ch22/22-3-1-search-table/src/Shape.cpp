/*
 * Shape.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Shape.h"
#include <iostream>
using namespace std;

bool intersect_circle_circle(const Shape& s1, const Shape& s2)
{
	cout << "intersect_circle_circle()\n";
	return true;
}

bool intersect_circle_triangle(const Shape& s1, const Shape& s2)
{
	cout << "intersect_circle_triangle()\n";
	return true;
}

bool intersect_triangle_circle(const Shape& s1, const Shape& s2)
{
	cout << "intersect_triangle_circle()\n";
	return true;
}

bool intersect_triangle_triangle(const Shape& s1, const Shape& s2)
{
	cout << "intersect_triangle_triangle()\n";
	return true;
}

typedef bool (*PFN_INTERSECT)(const Shape&, const Shape&);

PFN_INTERSECT intersect_tbl[] =
{
	intersect_circle_circle,
	intersect_circle_triangle,
	intersect_triangle_circle,
	intersect_triangle_triangle
};

int index(const Shape& s1, const Shape& s2)
{
	return s1.type_id() * Shape::N_TID + s2.type_id();
}

bool intersect(const Shape& s1, const Shape& s2)
{
	auto i = index(s1,s2);
	return intersect_tbl[i](s1,s2);
}

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

Shape::PFN_INTERSECT Shape::intersect_tbl[] =
{
	intersect_circle_circle,
	intersect_circle_triangle,
	intersect_triangle_circle,
	intersect_triangle_triangle
};

bool Shape::intersect(const Shape& s1, const Shape& s2)
{
	auto i = s1.type_id()*N_TID+s2.type_id();
	return intersect_tbl[i](s1,s2);
}

/*
 * Shape.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Shape.h"
#include <iostream>
using namespace std;

Rectangle Rectangle::box() const
{
	cout << "Rectangle::box()\n";
	return Rectangle{*this};
};

Rectangle Circle::box() const
{
	cout << "Circle::box()\n";
	return Rectangle{ };
};

Rectangle Triangle::box() const
{
	cout << "Triangle::box()\n";
	return Rectangle{ };
};

bool intersect(const Rectangle&, const Rectangle&)
{
	return true;
}

/*
 * circle.cpp
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "circle.h"

Circle::Circle(Point p, int rr)
: x{p}, r{rr}
{
}

void Circle::draw() const
{
	cout << "Circle::draw() called\n" ;
}

void Circle::rotate(int angle)
{
	cout << "Circle::rotate() called\n" ;
}

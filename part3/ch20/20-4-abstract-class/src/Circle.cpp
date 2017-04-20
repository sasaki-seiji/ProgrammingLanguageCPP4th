/*
 * Circle.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(Point p, int r)
	: center{p}, radius{r}
{
}

void Circle::draw() const
{
	cout << "Circle::draw(): "
			<< "center=" << center << ", radius=" << radius << "\n";
}


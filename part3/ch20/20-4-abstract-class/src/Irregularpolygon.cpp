/*
 * Irregularpolygon.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#include "Irregularpolygon.h"
#include <iostream>
using namespace std;

Irregular_polygon::Irregular_polygon(initializer_list<Point> points)
	: lp{points}
{
}

void Irregular_polygon::draw() const
{
	cout << "Irregular_polygon::draw(): points=";
	for (auto pt : lp)
		cout << pt << ",";
	cout << endl;
}

void Irregular_polygon::rotate(int angle)
{
	cout << "Irregular_polygon::rotate(" << angle << ")\n";
}

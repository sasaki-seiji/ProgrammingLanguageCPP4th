/*
 * Shape.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Shape.h"
#include <iostream>
using namespace std;

void Circle::draw()
{
	cout << "Circle::draw():\n";
	cout << "center: {" << c.x << ", " << c.y << "}, radius: " << r << '\n';
}

void Triangle::draw()
{
	cout << "Triangle::draw():\n";
	cout << "vertex1: {" << pt1.x << ", " << pt1.y
			<< "}, vertex2: {" << pt2.x << ", " << pt2.y
			<< "}, vertex3: {" << pt3.x << ", " << pt3.y << "}\n";
}

void Square::draw()
{
	cout << "Square::draw():\n";
	cout << "left: " << left << ", top: " << top
			<< ", width: " << width << ", height: " << height << '\n';
}


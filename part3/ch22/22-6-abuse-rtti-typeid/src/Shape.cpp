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

void Circle::rotate()
{
	cout << "Circle::rotate()\n";
}

void Triangle::draw()
{
	cout << "Triangle::draw():\n";
	cout << "vertex1: {" << pt1.x << ", " << pt1.y
			<< "}, vertex2: {" << pt2.x << ", " << pt2.y
			<< "}, vertex3: {" << pt3.x << ", " << pt3.y << "}\n";
}

void Triangle::rotate()
{
	cout << "Triangle::rotate()\n";
	// difficult
}

void Square::draw()
{
	cout << "Square::draw():\n";
	cout << "left: " << left << ", top: " << top
			<< ", width: " << width << ", height: " << height << '\n';
}

void Square::rotate()
{
	cout << "Square::rotate()\n";
	int center_x, center_y;
	center_x = (left+left+width)/2;
	center_y = (top+top+height)/2;
	left = center_x - height/2;
	top = center_y - width/2;
	std::swap(width,height);
}

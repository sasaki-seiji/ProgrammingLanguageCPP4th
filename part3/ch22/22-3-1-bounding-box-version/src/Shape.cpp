/*
 * Shape.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Shape.h"
#include <iostream>
#include <algorithm>
using namespace std;

Rectangle Rectangle::box() const
{
	return Rectangle{*this};
};

Rectangle Circle::box() const
{
	return Rectangle{x-radius, y-radius, radius*2, radius*2};
};

ostream& operator<<(ostream& os, const Circle& c)
{
	return os << "Circle(" << c.x << "," << c.y << "," << c.radius << ")";
}

Rectangle Triangle::box() const
{
	int min_x, max_x, min_y, max_y;
	min_x = min({x1,x2,x3});
	max_x = max({x1,x2,x3});
	min_y = min({y1,y2,y3});
	max_y = max({y1,y2,y3});
	return Rectangle{min_x, min_y, max_x-min_x, max_y-min_y};
};

ostream& operator<<(ostream& os, const Triangle& t)
{
	return os << "Triangle(" << t.x1 << "," << t.y1
				<< "," << t.x2 << "," << t.y2
				<< "," << t.x3 << "," << t.y3 << ")";
}

bool intersect(const Rectangle& r1, const Rectangle& r2)
{
	if (r1.left+r1.width <= r2.left || r2.left+r2.width <= r1.left) return false;
	if (r1.top+r1.height <= r2.top || r2.top+r2.height <= r1.top ) return false;

	return true;
}

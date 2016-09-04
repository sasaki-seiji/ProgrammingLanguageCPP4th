/*
 * Ioshape.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Ioshape.h"

Io_circle::Io_circle(istream& is)
{
	int cx, cy, r;
	is >> cx;
	is >> cy;
	is >> r;
	Point c{cx,cy};
	center(c);
	radius(r);
}

Io_triangle::Io_triangle(istream& is)
{
	int x,y;
	Point pt;

	is >> x >> y;
	pt = {x,y};
	vertex1(pt);

	is >> x >> y;
	pt = {x,y};
	vertex2(pt);

	is >> x >> y;
	pt = {x,y};
	vertex3(pt);
}


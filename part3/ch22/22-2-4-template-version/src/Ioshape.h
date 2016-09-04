/*
 * Ioshape.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef IOSHAPE_H_
#define IOSHAPE_H_

#include "Shape.h"
#include "Ioobj.h"
#include <iostream>
using std::istream;

template<typename T>
struct Io : T, Io_obj {
	Io(istream&);
	Io* clone() const { return new Io{*this}; }

	// 2016.09.04 bug-fix
	//static Io* new_io(istream& is) { return new Io{is}; }
	static Io_obj* new_io(istream& is) { return new Io{is}; }
};

using Io_circle = Io<Circle>;
using Io_triangle = Io<Triangle>;

template<>
Io<Circle>::Io(istream& is)
{
	int cx, cy, r;
	is >> cx;
	is >> cy;
	is >> r;
	Point c{cx,cy};
	center(c);
	radius(r);
}

template<>
Io<Triangle>::Io(istream& is)
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

#endif /* IOSHAPE_H_ */

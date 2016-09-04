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
struct Io : Io_obj {
	T val;

	Io(istream&);
	Io* clone() const { return new Io{*this}; }

	// 2016.09.04 bug-fix
	//static Io* new_io(istream& is) { return new Io{is}; }
	static Io_obj* new_io(istream& is) { return new Io{is}; }
};

// 2016.09.04 bug-fix
template<typename T>
//T* get_val<T>(Io_obj* p)
	// expected initializer before '<' token
T* get_val(Io_obj* p)
{
	if (auto pp = dynamic_cast<Io<T>*>(p))
		return &pp->val;
	return nullptr;
}

using Io_circle = Io<Circle>;
using Io_triangle = Io<Triangle>;
using Io_int = Io<int>;

template<>
Io<Circle>::Io(istream& is)
{
	int cx, cy, r;
	is >> cx;
	is >> cy;
	is >> r;
	Point c{cx,cy};
	val.center(c);
	val.radius(r);
}

template<>
Io<Triangle>::Io(istream& is)
{
	int x,y;
	Point pt;

	is >> x >> y;
	pt = {x,y};
	val.vertex1(pt);

	is >> x >> y;
	pt = {x,y};
	val.vertex2(pt);

	is >> x >> y;
	pt = {x,y};
	val.vertex3(pt);
}

template<>
Io<int>::Io(istream& is)
{
	is >> val;
}

#endif /* IOSHAPE_H_ */

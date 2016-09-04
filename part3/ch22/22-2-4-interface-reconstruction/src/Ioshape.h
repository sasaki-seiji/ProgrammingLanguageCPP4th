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

struct Io_circle : Circle, Io_obj {
	Io_circle(istream&);
	Io_circle* clone() const { return new Io_circle{*this}; }
	static Io_obj* new_circle(istream& is) { return new Io_circle{is}; }
};

struct Io_triangle : Triangle, Io_obj {
	Io_triangle(istream&);
	Io_triangle* clone() const { return new Io_triangle{*this}; }
	static Io_obj* new_triangle(istream& is) { return new Io_triangle{is}; }
};

#endif /* IOSHAPE_H_ */

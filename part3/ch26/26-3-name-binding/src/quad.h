/*
 * quad.h
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#ifndef QUAD_H_
#define QUAD_H_

struct Quad {
	long double val;
	Quad(long double v = 0) : val{v} { }
	operator long double() { return val; }
};

#endif /* QUAD_H_ */

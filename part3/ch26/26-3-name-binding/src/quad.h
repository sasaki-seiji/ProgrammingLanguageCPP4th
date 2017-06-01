/*
 * quad.h
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#ifndef QUAD_H_
#define QUAD_H_

class Quad {
	long double val;
public:
	Quad(long double v = 0) : val{v} { }
	long double value() const { return val; }
};

Quad operator+(Quad q1, Quad q2)
{
	return Quad(q1.value()+q2.value());
}

std::ostream& operator<<(std::ostream& os, Quad q)
{
	return os << q.value();
}
#endif /* QUAD_H_ */

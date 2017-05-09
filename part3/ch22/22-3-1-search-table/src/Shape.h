/*
 * Shape.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Circle;
class Triangle;

class Shape {
public:
	enum type { TID_CIRCLE, TID_TRIANGLE, N_TID };
	type type_id() const { return tid; }

	Shape(type tid) : tid{tid} { }
	virtual ~Shape() { }

private:
	type tid;
};

class Circle : public Shape {
public:
	Circle() : Shape{TID_CIRCLE} { }
};

class Triangle : public Shape {
public:
	Triangle() : Shape{TID_TRIANGLE} { }
};

bool intersect(const Shape& s1, const Shape& s2);

#endif /* SHAPE_H_ */

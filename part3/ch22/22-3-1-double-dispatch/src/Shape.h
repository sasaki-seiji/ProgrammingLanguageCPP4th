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
	virtual bool intersect(const Shape&) const = 0;
	virtual bool intersect(const Circle&) const = 0;
	virtual bool intersect(const Triangle&) const = 0;

	virtual ~Shape() { }
};

class Circle : public Shape {
public:
	bool intersect(const Shape&) const override;
	bool intersect(const Circle&) const override;
	bool intersect(const Triangle&) const override;
};

class Triangle : public Shape {
public:
	bool intersect(const Shape&) const override;
	bool intersect(const Circle&) const override;
	bool intersect(const Triangle&) const override;
};

#endif /* SHAPE_H_ */

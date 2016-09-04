/*
 * Shape.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Rectangle;
class Circle;
class Triangle;

class Shape {
public:
	virtual Rectangle box() const = 0;

	virtual ~Shape() { }
};

class Rectangle : public Shape {
public:
	Rectangle box() const override;
};

class Circle : public Shape {
public:
	Rectangle box() const override;
};

class Triangle : public Shape {
public:
	Rectangle box() const override;
};

bool intersect(const Rectangle&, const Rectangle&);
inline bool intersect(const Shape& s1, const Shape& s2)
{
	return intersect(s1.box(), s2.box());
}

#endif /* SHAPE_H_ */

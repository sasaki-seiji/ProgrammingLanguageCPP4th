/*
 * Shape.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
using namespace std;

class Rectangle;
class Circle;
class Triangle;

class Shape {
public:
	virtual Rectangle box() const = 0;
	virtual ~Shape() { }
};

struct Rectangle : public Shape {
	Rectangle(int l, int t, int w, int h)
		: left{l}, top{t}, width{w}, height{h} { }
	Rectangle box() const override;

	int left, top, width, height;
};

class Circle : public Shape {
public:
	Circle(int x, int y, int r)
		:x{x}, y{y}, radius{r} { }
	Rectangle box() const override;
private:
	int x, y;
	int radius;
	friend ostream& operator<<(ostream&, const Circle&);
};

class Triangle : public Shape {
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
		: x1{x1}, y1{y1}, x2{x2}, y2{y2}, x3{x3}, y3{y3} { }
	Rectangle box() const override;
private:
	int x1, y1;
	int x2, y2;
	int x3, y3;
	friend ostream& operator<<(ostream&, const Triangle&);
};

bool intersect(const Rectangle&, const Rectangle&);
inline bool intersect(const Shape& s1, const Shape& s2)
{
	return intersect(s1.box(), s2.box());
}

#endif /* SHAPE_H_ */

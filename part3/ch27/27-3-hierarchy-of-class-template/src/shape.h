/*
 * shape.h
 *
 *  Created on: 2016/09/28
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <typeinfo>

struct Point {
	int x,y;
};

template<typename Color_scheme, typename Canvas>
class Shape {
public:
	virtual void draw() const = 0;
	virtual ~Shape() { }

protected:
	Color_scheme scheme{};
	Canvas canvas{};
};

template<typename Color_scheme, typename Canvas>
class Circle : public Shape<Color_scheme,Canvas> {
	Point center;
	int radius;
public:
	Circle(Point p={0,0}, int r=0) : center{p}, radius{r} { }
	void draw() const override
	{
		std::cout << "Circle<"
					<< typeid(this->scheme).name() << ","
					<< typeid(this->canvas).name() << ">({"
					<< center.x << "," << center.y << "},"
					<< radius << ")\n";
	}
};

template<typename Color_scheme, typename Canvas>
class Triangle : public Shape<Color_scheme,Canvas> {
	Point pt1, pt2, pt3;
public:
	Triangle(Point p1, Point p2, Point p3) :pt1{p1}, pt2{p2}, pt3{p3} { }
	void draw() const override
	{
		std::cout << "Triangle<"
				<< typeid(this->scheme).name() << ","
				<< typeid(this->canvas).name() << ">({"
				<< pt1.x << "," << pt1.y << "},{"
				<< pt2.x << "," << pt2.y << "},{"
				<< pt3.x << "," << pt3.y << "})\n";
	}

};

struct RGB { };
struct Bitmapped { };

#endif /* SHAPE_H_ */

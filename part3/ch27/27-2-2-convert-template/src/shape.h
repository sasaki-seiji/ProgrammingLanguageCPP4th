/*
 * shape.h
 *
 *  Created on: 2016/09/28
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>

struct Point {
	int x,y;
};

class Shape {
public:
	virtual void draw() const = 0;
	virtual ~Shape() { }
};

class Circle : public Shape {
	Point center;
	int radius;
public:
	Circle(Point p={0,0}, int r=0) : center{p}, radius{r} { }
	void draw() const override
	{
		std::cout << "Circle({"
					<< center.x << "," << center.y << "},"
					<< radius << ")\n";
	}
};

class Triangle : public Shape {
	Point pt1, pt2, pt3;
public:
	Triangle(Point p1, Point p2, Point p3) :pt1{p1}, pt2{p2}, pt3{p3} { }
	void draw() const override
	{
		std::cout << "Triangle({"
				<< pt1.x << "," << pt1.y << "},{"
				<< pt2.x << "," << pt2.y << "},{"
				<< pt3.x << "," << pt3.y << "})\n";
	}

};

#endif /* SHAPE_H_ */

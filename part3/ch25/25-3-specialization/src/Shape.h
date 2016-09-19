/*
 * Shape.h
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() { }
};

class Circle : public Shape {
	int center_x;
	int center_y;
	int radius;
public:
	Circle(int x, int y, int r) :center_x{x}, center_y{y}, radius{r} { }
	void draw() override
	{
		std::cout << "Circle(" << center_x << "," << center_y <<
				"," << radius << ")\n";
	}
};

class Rectangle : public Shape {
	int left, top;
	int width, height;
public:
	Rectangle(int x, int y, int w, int h)
		:left{x}, top{y}, width{w}, height{h} { }
	void draw() override
	{
		std::cout << "Rectangle(" << left << "," << top <<
				"," << width << "," << height << ")\n";
	}
};

#endif /* SHAPE_H_ */

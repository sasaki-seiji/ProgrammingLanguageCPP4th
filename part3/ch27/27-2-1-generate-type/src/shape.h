/*
 * shape.h
 *
 *  Created on: 2016/09/28
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

struct Point {
	int x,y;
};

class Shape {

};

class Circle : public Shape {
	Point center;
	int radius;
public:
	Circle(Point p, int r) : center{p}, radius{r} { }
};

class Triangle : public Shape {
	Point pt1, pt2, pt3;
public:
	Triangle(Point p1, Point p2, Point p3) :pt1{p1}, pt2{p2}, pt3{p3} { }

};

#endif /* SHAPE_H_ */

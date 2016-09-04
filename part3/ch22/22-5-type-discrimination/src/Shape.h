/*
 * Shape.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() { }
};

struct Point {
	int x, y;
};

class Circle : public Shape {
public:
	void draw() override;

	Circle(Point cc={0,0}, int rr={0}) : c{cc}, r{rr} { }
	Point center() const { return c; }
	void center(Point cc) { c = cc; }
	int radius() const { return r; }
	void radius(int rr) { r = rr; }
private:
	Point c;
	int r;
};

class Triangle : public Shape {
public:
	void draw() override;

	Triangle(Point p1={0,0}, Point p2={0,0}, Point p3={0,0})
		: pt1{p1}, pt2{p2}, pt3{p3} { }
	Point vertex1() const { return pt1; }
	Point vertex2() const { return pt2; }
	Point vertex3() const { return pt3; }
	void vertex1(Point p1) { pt1 = p1; }
	void vertex2(Point p2) { pt2 = p2; }
	void vertex3(Point p3) { pt3 = p3; }
private:
	Point pt1,pt2,pt3;
};

#endif /* SHAPE_H_ */

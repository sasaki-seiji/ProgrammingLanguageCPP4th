/*
 * Shape.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
	virtual void rotate(int) = 0;
	virtual void draw() const = 0;
	virtual bool is_closed() const = 0;

	virtual ~Shape();
};

class Point {
public:
	int x, y;
};
#endif /* SHAPE_H_ */

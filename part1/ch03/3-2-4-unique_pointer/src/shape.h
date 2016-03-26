/*
 * shape.h
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

struct Point {
	int	x, y;
};

class Shape {
public:
	virtual Point center() const = 0;
	virtual void move(Point to) = 0;
	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;
	virtual ~Shape() {}
};


#endif /* SHAPE_H_ */

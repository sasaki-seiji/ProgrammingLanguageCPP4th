/*
 * circle.h
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "shape.h"

class Circle : public Shape {
public:
	Circle(Point p, int rr);

	Point center() const { return x; }
	void move(Point to) { x = to; }
	void draw() const;
	void rotate(int) ;
private:
	Point x;
	int	r;
};

#endif /* CIRCLE_H_ */

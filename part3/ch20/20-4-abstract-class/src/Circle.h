/*
 * Circle.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public Shape {
public:
	Circle(Point p, int r);

	void rotate(int) override { }
	void draw() const override;
	bool is_closed() const { return true; }
private:
	Point center;
	int radius;
};

#endif /* CIRCLE_H_ */

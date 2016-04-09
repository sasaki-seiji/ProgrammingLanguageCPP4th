/*
 * smiley.h
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#ifndef SMILEY_H_
#define SMILEY_H_

#include <vector>
#include "circle.h"

class Smiley : public Circle {
public:
	Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} { }

	~Smiley()
	{
		delete mouth;
		for (auto p : eyes) delete p;
	}

	void move(Point to) { Circle::move(to); }
	void draw() const;
	void rotate(int);
	void add_eye(Shape* s) { eyes.push_back(s); }
	void set_mouth(Shape* s) { mouth = s; }
	virtual void wink(int i) { }

private:
	std::vector<Shape*> eyes;
	Shape*	mouth;
};

#endif /* SMILEY_H_ */

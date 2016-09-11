/*
 * Shape.h
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>

class Shape {
public:
	virtual ~Shape() { }
	virtual void draw() const = 0;
	template<typename T>
		//virtual bool intersect(const T&) const = 0;
			// error: templates may not be 'virtual'
		bool intersect(const T&) const;
			// error: templates may not be 'virtual'
};

class Circle : public Shape {
public:
	void draw() const override { std::cout << "Cirle::draw()\n" << '\n'; }
};

#endif /* SHAPE_H_ */

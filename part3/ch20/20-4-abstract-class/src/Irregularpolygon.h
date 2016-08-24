/*
 * Irregularpolygon.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef IRREGULARPOLYGON_H_
#define IRREGULARPOLYGON_H_

#include "Polygon.h"
#include <list>
#include <initializer_list>
using std::list;
using std::initializer_list;

class Irregular_polygon : public Polygon {
	list<Point> lp;
public:
	Irregular_polygon(initializer_list<Point>);

	void draw() const override;
	void rotate(int) override;
};

#endif /* IRREGULARPOLYGON_H_ */

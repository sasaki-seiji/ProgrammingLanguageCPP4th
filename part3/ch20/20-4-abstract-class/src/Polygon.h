/*
 * Polygon.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape {
public:
	bool is_closed() const override { return true; }
	virtual ~Polygon();
};

#endif /* POLYGON_H_ */

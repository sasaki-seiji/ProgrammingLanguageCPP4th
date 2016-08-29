/*
 * Satellite.h
 *
 *  Created on: 2016/08/29
 *      Author: sasaki
 */

#ifndef SATELLITE_H_
#define SATELLITE_H_

struct Pos {
	double x,y,z;
};

class Satellite {
public:
	virtual Pos center() const = 0;
};

Pos center_of_gravity(const Satellite*);

#endif /* SATELLITE_H_ */

/*
 * Commsat.h
 *
 *  Created on: 2016/08/29
 *      Author: sasaki
 */

#ifndef COMMSAT_H_
#define COMMSAT_H_

#include "Satellite.h"
#include "Displayed.h"

class Comm_sat : public Satellite, public Displayed {
	Pos pos;
public:
	Comm_sat(Pos p) : pos{p} { }
	Pos center() const override;
	void draw() override;
};

#endif /* COMMSAT_H_ */

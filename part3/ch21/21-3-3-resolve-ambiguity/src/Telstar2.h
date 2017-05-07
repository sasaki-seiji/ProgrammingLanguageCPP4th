/*
 * Telstart2.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef TELSTAR2_H_
#define TELSTAR2_H_

#include "Commsat2.h"
#include <iostream>
using namespace std;

class Telstar2 : public Comm_sat2 {
public:
	void draw()
	{
		Comm_sat2::draw();
		cout << "Telstar2::draw() : internal process\n";
	}
};

#endif /* TELSTAR2_H_ */

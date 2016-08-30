/*
 * Commsat2.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef COMMSAT2_H_
#define COMMSAT2_H_

#include "Satellite.h"
#include "Displayed.h"

class Comm_sat2 : public Satellite, public Displayed {
public:
	Debug_info get_debug()
	{
		Debug_info di1 = Satellite::get_debug();
		Debug_info di2 = Displayed::get_debug();
		return merge_info(di1, di2);
	}
};

#endif /* COMMSAT2_H_ */

/*
 * Displayed.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef DISPLAYED_H_
#define DISPLAYED_H_

#include "Debuginfo.h"

class Displayed {
public:
	virtual Debug_info get_debug();
	virtual void draw();
};

#endif /* DISPLAYED_H_ */

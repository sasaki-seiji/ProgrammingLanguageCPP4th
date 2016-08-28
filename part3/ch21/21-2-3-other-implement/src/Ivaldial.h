/*
 * Ivaldial.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef IVALDIAL_H_
#define IVALDIAL_H_

#include "Ivalbox.h"

class Ival_dial : public Ival_box {
public:
	virtual void right(int) = 0;
	virtual void left(int) = 0;
};

#endif /* IVALDIAL_H_ */

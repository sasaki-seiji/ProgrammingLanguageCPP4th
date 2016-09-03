/*
 * Ivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef IVALSLIDER_H_
#define IVALSLIDER_H_

#include "Ivalbox.h"

class Ival_slider : public Ival_box{
public:
	virtual void up() = 0;
	virtual void down() = 0;
};

#endif /* IVALSLIDER_H_ */

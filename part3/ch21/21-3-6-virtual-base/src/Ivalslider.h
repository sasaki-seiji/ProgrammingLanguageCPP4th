/*
 * Ivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef IVALSLIDER_H_
#define IVALSLIDER_H_

#include "Ivalbox.h"

class Ival_slider : public virtual Ival_box{
public:
	virtual void incr() = 0;
	virtual void decr() = 0;
};

#endif /* IVALSLIDER_H_ */

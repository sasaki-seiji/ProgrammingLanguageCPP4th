/*
 * Ivalslider.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALSLIDER_H_
#define IVALSLIDER_H_

#include "Ivalbox.h"

class Ival_slider : public Ival_box{
private:

public:
	Ival_slider(int,int);

	int get_value() override;
	void prompt() override;
};

#endif /* IVALSLIDER_H_ */

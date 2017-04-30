/*
 * Flashingivalslider.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef FLASHINGIVALSLIDER_H_
#define FLASHINGIVALSLIDER_H_

#include "Ivalslider.h"

class Flashing_ival_slider : public Ival_slider {
public:
	Flashing_ival_slider(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);

	void prompt() override;
};

#endif /* FLASHINGIVALSLIDER_H_ */

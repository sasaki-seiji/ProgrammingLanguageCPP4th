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
	Flashing_ival_slider(int low, int high, int t, int l, int w=0, int h=0)
		: Ival_slider{low, high, t, l, w, h} { }

	void prompt() override;
};

#endif /* FLASHINGIVALSLIDER_H_ */

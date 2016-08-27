/*
 * Popupivalslider.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef POPUPIVALSLIDER_H_
#define POPUPIVALSLIDER_H_

#include "Ivalslider.h"

class Popup_ival_slider : public Ival_slider {
public:
	Popup_ival_slider(int ll, int hh) : Ival_slider{ll,hh} { }

	void prompt() override;
};

#endif /* POPUPIVALSLIDER_H_ */

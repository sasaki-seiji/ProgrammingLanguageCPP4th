/*
 * BBpopupivalslider.h
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#ifndef BBPOPUPIVALSLIDER_H_
#define BBPOPUPIVALSLIDER_H_

#include "Popupivalslider.h"
#include "BBivalslider.h"

class BB_popup_ival_slider : public virtual Popup_ival_slider, protected BB_ival_slider {
public:
	BB_popup_ival_slider(int ll, int hh) : BB_ival_slider{ll, hh} { }

	void popup() override ;
	void popdown() override ;
};

#endif /* BBPOPUPIVALSLIDER_H_ */

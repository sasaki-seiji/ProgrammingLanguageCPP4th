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
	Popup_ival_slider(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);

	void prompt() override;
	void display_info() const override;

	void popup();
	void popdown();

};

#endif /* POPUPIVALSLIDER_H_ */

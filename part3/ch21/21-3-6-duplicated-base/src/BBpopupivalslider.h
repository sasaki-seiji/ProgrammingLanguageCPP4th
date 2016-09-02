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

class BB_popup_ival_slider : public Popup_ival_slider, protected BB_ival_slider {
public:
	BB_popup_ival_slider(int ll, int hh) : BB_ival_slider{ll, hh} { }

	int get_value() override { return BB_ival_slider::get_value(); }
	void set_value(int i) override { BB_ival_slider::set_value(i); }
	void reset_value(int i) override { BB_ival_slider::reset_value(i); }
	void prompt() override { BB_ival_slider::prompt(); }
	bool was_changed() const override { return BB_ival_slider::was_changed(); }

	void up() override { BB_ival_slider::up(); }
	void down() override { BB_ival_slider::down(); }

	void popup() override ;
	void popdown() override ;
};

#endif /* BBPOPUPIVALSLIDER_H_ */

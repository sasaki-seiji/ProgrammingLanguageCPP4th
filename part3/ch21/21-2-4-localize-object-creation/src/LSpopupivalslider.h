/*
 * LSpopupivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSPOPUPIVALSLIDER_H_
#define LSPOPUPIVALSLIDER_H_

#include "Popupivalslider.h"
#include "LSslider.h"

class LS_popup_ival_slider : public Popup_ival_slider, protected LSslider {
public:
	LS_popup_ival_slider(int ll, int hh) : LSslider{ll, hh} { }
	~LS_popup_ival_slider() { }

	int get_value() override { return LSslider::get_value(); }
	void set_value(int i) override { LSslider::set_value(i); }
	void reset_value(int i) override { LSslider::reset_value(i); }
	void prompt() override { LSslider::prompt("LS_popup_ival_slider"); }
	bool was_changed() const override { return LSslider::was_changed(); }

	void up() override { LSslider::up(); }
	void down() override { LSslider::down(); }

	void popup() override ;
	void popdown() override ;
};

#endif /* LSPOPUPIVALSLIDER_H_ */

/*
 * CWivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef CWIVALSLIDER_H_
#define CWIVALSLIDER_H_

#include "Ivalslider.h"
#include "CWslider.h"

class CW_ival_slider : public Ival_slider, protected CWslider {
public:
	CW_ival_slider(int ll, int hh) :CWslider{ll,hh} { }
	~CW_ival_slider() { }

	int get_value() override { return CWslider::get_value(); }
	void set_value(int i) override { CWslider::set_value(i); }
	void reset_value(int i) override { CWslider::reset_value(i); }
	void prompt() override { CWslider::prompt("CW_ival_slider"); }
	bool was_changed() const override { return CWslider::was_changed(); }

	void up() override { CWslider::up(); }
	void down() override { CWslider::down(); }
};

#endif /* CWIVALSLIDER_H_ */

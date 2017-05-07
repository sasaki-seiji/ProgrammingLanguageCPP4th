/*
 * Myslider.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef MYSLIDER_H_
#define MYSLIDER_H_

#include "Ivalslider.h"

class My_slider : public Ival_slider {
public:
	int get_value() override { return 0; }
	void set_value(int i) override { }
	void reset_value(int i) override { }
	void prompt() override { }
	bool was_changed() const override { return false; }

	void incr() override { }
	void decr() override { }

	void display_info() const;
};

#endif /* MYSLIDER_H_ */

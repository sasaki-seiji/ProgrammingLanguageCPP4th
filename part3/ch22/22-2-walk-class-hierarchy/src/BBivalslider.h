/*
 * BBivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef BBIVALSLIDER_H_
#define BBIVALSLIDER_H_

#include "Ivalslider.h"
#include "BBslider.h"

class BB_ival_slider : public Ival_slider, public BBslider {
public:
	BB_ival_slider(int, int);
	~BB_ival_slider() { }

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void up() override;
	void down() override;
};

#endif /* BBIVALSLIDER_H_ */

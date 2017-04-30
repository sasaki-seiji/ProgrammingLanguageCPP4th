/*
 * BBflashingivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef BBFLASHINGIVALSLIDER_H_
#define BBFLASHINGIVALSLIDER_H_

#include "Flashingivalslider.h"
#include "BBwidgetwithbellsandwhistles.h"

class BB_flashing_ival_slider : public Flashing_ival_slider,
		protected BBwidget_with_bells_and_whistles {
public:
	BB_flashing_ival_slider(int low, int high, int l=0, int t=0, int w=0, int h=0);
	~BB_flashing_ival_slider() { }

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void incr() override;
	void decr() override;

	void flash() override;

	void display_info() const override;

protected:
	void on_changed(int i) override;

private:
	bool changed;
};

#endif /* BBFLASHINGIVALSLIDER_H_ */

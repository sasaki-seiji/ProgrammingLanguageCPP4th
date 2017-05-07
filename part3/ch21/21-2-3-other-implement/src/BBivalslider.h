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

class BB_ival_slider : public Ival_slider, protected BBslider {
public:
	BB_ival_slider(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);
	~BB_ival_slider() { }

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void incr() override;
	void decr() override;

	void display_info() const override;

protected:
	void on_changed(int i) override;

private:
	bool changed;
};

#endif /* BBIVALSLIDER_H_ */

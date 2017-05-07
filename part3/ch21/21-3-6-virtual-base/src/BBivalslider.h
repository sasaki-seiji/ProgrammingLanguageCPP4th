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

class BB_ival_slider : public virtual Ival_slider, protected BBslider {
public:
	BB_ival_slider(int low, int high, int l=0, int t=0, int w=0, int h=0);
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

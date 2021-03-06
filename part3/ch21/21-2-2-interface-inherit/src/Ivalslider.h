/*
 * Ivalslider.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALSLIDER_H_
#define IVALSLIDER_H_

#include "Ivalbox.h"
#include "BBwidget.h"

class Ival_slider : public Ival_box, protected BBwidget {
public:
	Ival_slider(int low,int high, int l=-1, int t=-1, int w=-1, int h=-1, bool visible=true);
	~Ival_slider() override;

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void display_info() const override;

	void incr();
	void decr();

protected:
	void on_mouse1hit(int x, int y) override;

protected:
	int val;
	int low, high;
	bool changed {false};
};

#endif /* IVALSLIDER_H_ */

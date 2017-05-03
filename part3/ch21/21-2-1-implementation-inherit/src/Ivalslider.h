/*
 * Ivalslider.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALSLIDER_H_
#define IVALSLIDER_H_

#include "Ivalbox.h"

class Ival_slider : public Ival_box{
private:

public:
	Ival_slider(int low,int high, int l=-1, int t=-1, int w=-1, int h=-1);

	int get_value() override;
	void prompt() override;
	void display_info() const override;

	void incr();
	void decr();
	void on_mouse1hit(int x, int y) override;
};

#endif /* IVALSLIDER_H_ */

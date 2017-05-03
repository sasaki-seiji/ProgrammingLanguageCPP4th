/*
 * Ivaldial.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALDIAL_H_
#define IVALDIAL_H_

#include "Ivalbox.h"

class Ival_dial : public Ival_box{
private:

public:
	Ival_dial(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);

	int get_value() override;
	void prompt() override;

	void display_info() const override;

	void turn_left();
	void turn_right();
	void on_mouse1hit(int x, int y) override;
};

#endif /* IVALDIAL_H_ */

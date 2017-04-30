/*
 * Ivaldial.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALDIAL_H_
#define IVALDIAL_H_

#include "Ivalbox.h"
#include "BBwidget.h"

class Ival_dial : public Ival_box, protected BBwidget {
public:
	Ival_dial(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);
	~Ival_dial() override;

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void display_info() const override;

	void turn_left();
	void turn_right();

protected:
	void on_mouse1hit(int x, int y) override;

private:
	int val;
	int low, high;
	bool changed {false};
};

#endif /* IVALDIAL_H_ */

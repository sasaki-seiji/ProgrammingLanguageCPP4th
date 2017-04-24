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
	Ival_slider(int,int);
	~Ival_slider() override;

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

protected:
	void on_up();
	void on_down();

private:
	int val;
	int low, high;
	bool changed {false};
};

#endif /* IVALSLIDER_H_ */

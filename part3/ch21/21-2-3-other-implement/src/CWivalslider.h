/*
 * CWivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef CWIVALSLIDER_H_
#define CWIVALSLIDER_H_

#include "Ivalslider.h"
#include "CWslider.h"

class CW_ival_slider : public Ival_slider, protected CWslider {
public:
	CW_ival_slider(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);
	~CW_ival_slider() { }

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void incr() override;
	void decr() override;

	void display_info() const override;

protected:
	virtual void on_updated(int i) override;

private:
	bool changed;
};

#endif /* CWIVALSLIDER_H_ */

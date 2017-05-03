/*
 * LSivaldial.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSIVALDIAL_H_
#define LSIVALDIAL_H_

#include "Ivaldial.h"
#include "LSdial.h"

class LS_ival_dial : public Ival_dial, protected LSdial {
public:
	LS_ival_dial(int ll, int hh, int l=-1, int t=-1, int w=-1, int h=-1);

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void turn_right() override;
	void turn_left() override;

	void display_info() const override;

protected:
	void on_changed(int i) override;


private:
	bool changed;
};

#endif /* LSIVALDIAL_H_ */

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
public:
	Ival_dial(int, int);
	~Ival_dial() override;

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

private:
	int val;
	int low, high;
	bool changed {false};
};

#endif /* IVALDIAL_H_ */

/*
 * Ivalbox.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALBOX_H_
#define IVALBOX_H_

#include "BBwidget.h"

class Ival_box : public BBwidget {
protected:
	int val;
	int low, high;
	bool changed {false};
public:
	Ival_box(int ll, int hh) : val{ll}, low{ll}, high{hh} { }

	virtual int get_value() { changed = false; return val; }
	virtual void set_value(int i) { changed = true; val = i; }
	virtual void reset_value(int i) { changed = false; val = i; }
	virtual void prompt() { }

	virtual ~Ival_box() { }
};

#endif /* IVALBOX_H_ */

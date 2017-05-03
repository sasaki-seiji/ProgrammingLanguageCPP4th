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
	Ival_box(int ll, int hh, int l=-1, int t=-1, int w=-1, int h=-1)
		: BBwidget{l,t,w,h}, val{ll}, low{ll}, high{hh} { }

	virtual int get_value() { changed = false; return val; }
	virtual void set_value(int i);
	virtual void reset_value(int i);
	virtual void prompt() { }
	virtual bool was_changed() const { return changed; }

	virtual ~Ival_box() { }

	// 2017.05.03 add
	virtual void display_info() const;
};

#endif /* IVALBOX_H_ */

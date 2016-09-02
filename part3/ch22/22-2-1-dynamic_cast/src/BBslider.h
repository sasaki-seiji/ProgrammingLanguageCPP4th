/*
 * BBslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef BBSLIDER_H_
#define BBSLIDER_H_

#include "BBwidget.h"

class BBslider : public BBwidget {
public:
	BBslider(int ll, int hh);
	~BBslider() { }

	virtual int value() { changed = false; return val; }
	virtual void value(int i) { changed = true; val = i; }
	virtual void reset(int i) { changed = false; val = i; }
	virtual void prompt(const char*);
	virtual bool was_changed() const { return changed; }

	virtual void incr();
	virtual void decr();

private:
	int val;
	int low, high;
	bool changed;
};

#endif /* BBSLIDER_H_ */

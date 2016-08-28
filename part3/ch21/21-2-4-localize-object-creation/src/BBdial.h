/*
 * BBdial.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef BBDIAL_H_
#define BBDIAL_H_

#include "BBwidget.h"

class BBdial : public BBwidget {
public:
	BBdial(int ll, int hh) : val{ll}, low{ll}, high{ll}, changed{false} { }
	~BBdial() { }

	virtual int value() { changed = false; return val; }
	virtual void value(int i) { changed = true; val = i; }
	virtual void reset(int i) { changed = false; val = i; }
	virtual void prompt(const char*);
	virtual bool was_changed() const { return changed; }

	virtual void right(int n) { changed = true; val+=n; }
	virtual void left(int n) { changed = true; val-=n; }

private:
	int val;
	int low, high;
	bool changed;
};

#endif /* BBDIAL_H_ */

/*
 * LSdial.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSDIAL_H_
#define LSDIAL_H_

#include "LSwidget.h"

class LSdial : public LSwidget {
public:
	LSdial(int ll, int hh) : val{ll}, low{ll}, high{ll}, changed{false} { }
	~LSdial() { }

	virtual int get_value() { changed = false; return val; }
	virtual void set_value(int i) { changed = true; val = i; }
	virtual void reset_value(int i) { changed = false; val = i; }
	virtual void prompt(const char*);
	virtual bool was_changed() const { return changed; }

	virtual void right(int n) { changed = true; val+=n; }
	virtual void left(int n) { changed = true; val+=n; }

private:
	int val;
	int low, high;
	bool changed;
};

#endif /* LSDIAL_H_ */

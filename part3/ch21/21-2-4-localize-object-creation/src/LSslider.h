/*
 * LSslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSSLIDER_H_
#define LSSLIDER_H_

#include "LSwidget.h"

class LSslider : public LSwidget {
public:
	LSslider(int ll, int hh) : val{ll}, low{ll}, high{hh}, changed{false} { }
	~LSslider() { }

	virtual int get_value() { changed = false; return val; }
	virtual void set_value(int i) { changed = true; val = i; }
	virtual void reset_value(int i) { changed = false; val = i; }
	virtual void prompt(const char*);
	virtual bool was_changed() const { return changed; }

	virtual void up() { changed = true; ++val; }
	virtual void down() { changed = true; --val; }

private:
	int val;
	int low, high;
	bool changed;
};

#endif /* LSSLIDER_H_ */

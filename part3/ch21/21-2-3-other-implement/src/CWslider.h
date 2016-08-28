/*
 * CWslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef CWSLIDER_H_
#define CWSLIDER_H_

#include "CWwidget.h"

class CWslider : public CWwidget {
public:
	CWslider(int ll, int hh);
	~CWslider() { }

	virtual int get_value() { changed = false; return val; }
	virtual void set_value(int i) { changed = true; val = i; }
	virtual void reset_value(int i) { changed = false; val = i; }
	virtual void prompt(const char*);
	virtual bool was_changed() const { return changed; }

	virtual void up(){ changed = true; ++val; }
	virtual void down(){ changed = true; --val; }

private:
	int val;
	int low, high;
	bool changed;
};

#endif /* CWSLIDER_H_ */

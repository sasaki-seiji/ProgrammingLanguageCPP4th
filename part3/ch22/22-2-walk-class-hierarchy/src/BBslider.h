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
	BBslider(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1,bool visible=true);
	~BBslider() { }

	int value() const { return val; }
	void value(int i) { if (lo <= i && i <= hi) val = i; }
	int low() const { return lo; }
	int high() const { return hi; }

protected:
	void on_mouse1hit(int x, int y) override;
	virtual void on_changed(int i) { }

private:
	int val;
	int lo, hi;
};

#endif /* BBSLIDER_H_ */

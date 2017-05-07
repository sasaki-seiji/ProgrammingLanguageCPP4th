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
	LSslider(int low, int high, int l=0, int t=0, int w=0, int h=0,bool visible=true);
	~LSslider() { }

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

#endif /* LSSLIDER_H_ */

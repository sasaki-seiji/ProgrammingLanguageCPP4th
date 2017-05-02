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
	CWslider(int low, int high, int l=0, int t=0, int w=0, int h=0);
	~CWslider() { }

	int value() const { return val; }
	void value(int i) { if (lo <= i && i <= hi ) val = i; }
	int low() const { return lo; }
	int high() const { return hi; }

protected:
	void on_mouse1hit(int x, int y) override;
	virtual void on_updated(int i) { }

private:
	int val;
	int lo, hi;
};

#endif /* CWSLIDER_H_ */

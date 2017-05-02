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
	void value(int i) { if (low <= i && i <= high ) val = i; }
	int get_low() const { return low; }
	int get_high() const { return high; }

protected:
	void on_mouse1hit(int x, int y) override;
	virtual void on_updated(int i) { }

private:
	int val;
	int low, high;
};

#endif /* CWSLIDER_H_ */

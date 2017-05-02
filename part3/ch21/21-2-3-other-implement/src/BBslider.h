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
	BBslider(int low, int high, int l=0, int t=0, int w=0, int h=0,bool visible=false);
	~BBslider() { }

	int value() const { return val; }
	void value(int i) { if (low <= i && i <= high) val = i; }
	int get_low() const { return low; }
	int get_high() const { return high; }

protected:
	void on_mouse1hit(int x, int y) override;
	virtual void on_changed(int i) { }

private:
	int val;
	int low, high;
};

#endif /* BBSLIDER_H_ */

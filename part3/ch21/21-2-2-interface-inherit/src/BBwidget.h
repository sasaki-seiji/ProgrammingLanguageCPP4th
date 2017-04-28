/*
 * BBwidget.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef BBWIDGET_H_
#define BBWIDGET_H_

class BBwidget {
private:
	int t, l, w, h;
public:
	BBwidget(int tt, int ll, int ww, int hh)
		:t(tt), l(ll), w(ww), h(hh) { }
	int top() const { return t; }
	int left() const { return l; }
	int width() const { return w; }
	int height() const { return h; }

protected:
	virtual void on_mouse1hit(int x, int y) { }
};

#endif /* BBWIDGET_H_ */

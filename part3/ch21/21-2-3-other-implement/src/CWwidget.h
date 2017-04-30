/*
 * CWwidget.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef CWWIDGET_H_
#define CWWIDGET_H_

#include "WinMgr.h"

class CWwidget : public Window {
private:
	static const int default_left = 10, default_top = 10,
			default_width = 80, default_height = 60;
public:
	CWwidget(int l=-1, int t=-1, int w=-1, int h=-1, bool visible=true);
	virtual ~CWwidget() { }
};

#endif /* CWWIDGET_H_ */

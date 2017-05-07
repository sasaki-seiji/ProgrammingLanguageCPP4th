/*
 * BBwidget.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef BBWIDGET_H_
#define BBWIDGET_H_

#include "WinMgr.h"

class BBwidget : public Window {
private:
	static const int default_left = 50, default_top = 50,
				default_width = 100, default_height = 60;
public:
	BBwidget(int l=-1, int t=-1, int w=-1, int h=-1, bool visible=true);
};

#endif /* BBWIDGET_H_ */

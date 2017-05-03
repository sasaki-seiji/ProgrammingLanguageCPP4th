/*
 * LSwidget.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSWIDGET_H_
#define LSWIDGET_H_

#include "WinMgr.h"

class LSwidget : public Window {
private:
	static const int default_left = 50, default_top = 50,
				default_width = 100, default_height = 60;
public:
	LSwidget(int l=-1, int t=-1, int w=-1, int h=-1, bool visible=true);
};

#endif /* LSWIDGET_H_ */

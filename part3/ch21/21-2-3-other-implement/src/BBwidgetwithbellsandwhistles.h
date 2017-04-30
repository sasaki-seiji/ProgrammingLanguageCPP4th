/*
 * BBwidgetwithbellsandwhistles.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef BBWIDGETWITHBELLSANDWHISTLES_H_
#define BBWIDGETWITHBELLSANDWHISTLES_H_

#include "BBslider.h"

class BBwidget_with_bells_and_whistles : public BBslider {
public:
	BBwidget_with_bells_and_whistles(int low, int high, int l=0, int t=0, int w=0, int h=0);
	~BBwidget_with_bells_and_whistles() override { }

	void flash();
};

#endif /* BBWIDGETWITHBELLSANDWHISTLES_H_ */

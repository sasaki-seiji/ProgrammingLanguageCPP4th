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
	BBwidget_with_bells_and_whistles(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);
	~BBwidget_with_bells_and_whistles() override { }

	void flash();
};

#endif /* BBWIDGETWITHBELLSANDWHISTLES_H_ */

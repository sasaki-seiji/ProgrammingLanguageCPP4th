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
	BBwidget_with_bells_and_whistles(int, int);
	~BBwidget_with_bells_and_whistles() override { }

	void prompt(const char*) override;
	virtual void flash();
};

#endif /* BBWIDGETWITHBELLSANDWHISTLES_H_ */

/*
 * Clock.h
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "Windowwithborder.h"
#include "Windowwithmenu.h"

class Clock : public Window_with_border, public Window_with_menu {
protected:
	void own_draw();
public:
	void draw() override;
};

#endif /* CLOCK_H_ */

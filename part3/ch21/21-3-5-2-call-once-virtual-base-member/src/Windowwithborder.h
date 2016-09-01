/*
 * Windowwithborder.h
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#ifndef WINDOWWITHBORDER_H_
#define WINDOWWITHBORDER_H_

#include "Window.h"

class Window_with_border : public virtual Window {
protected:
	void own_draw();
public:
	void draw() override;
};

#endif /* WINDOWWITHBORDER_H_ */

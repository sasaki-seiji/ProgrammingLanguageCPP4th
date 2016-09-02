/*
 * Windowwithborder.h
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#ifndef WINDOWWITHBORDER_H_
#define WINDOWWITHBORDER_H_

#include "Window.h"

class Window_with_border : public virtual Window {
public:
	void set_color(Color) override;
};

#endif /* WINDOWWITHBORDER_H_ */

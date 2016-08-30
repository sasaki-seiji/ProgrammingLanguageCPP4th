/*
 * WWindow.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef WWINDOW_H_
#define WWINDOW_H_

#include "Window.h"

class WWindow : public Window {
public:
	using Window::Window;
	virtual void win_draw() = 0;
	void draw() override final { win_draw(); }
};

#endif /* WWINDOW_H_ */

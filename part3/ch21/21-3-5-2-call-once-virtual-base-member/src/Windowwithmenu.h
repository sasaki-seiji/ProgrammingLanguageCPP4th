/*
 * Windowwithmenu.h
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#ifndef WINDOWWITHMENU_H_
#define WINDOWWITHMENU_H_

#include "Window.h"

class Window_with_menu : public virtual Window {
protected:
	void own_draw();
protected:
	void draw() override;
};

#endif /* WINDOWWITHMENU_H_ */

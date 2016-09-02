/*
 * Windowwithmenu.h
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#ifndef WINDOWWITHMENU_H_
#define WINDOWWITHMENU_H_

#include "Window.h"

class Window_with_menu : public virtual Window {
public:
	void prompt() override;
};

#endif /* WINDOWWITHMENU_H_ */

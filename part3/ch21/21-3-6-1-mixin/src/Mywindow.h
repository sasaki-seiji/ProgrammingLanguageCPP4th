/*
 * Mywindow.h
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Windowwithborder.h"
#include "Windowwithmenu.h"

class My_window : public Window_with_border, public Window_with_menu {
public:
	void prompt() override;
};

#endif /* MYWINDOW_H_ */

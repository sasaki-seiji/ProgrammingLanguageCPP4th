/*
 * Cowboywindow.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef COWBOYWINDOW_H_
#define COWBOYWINDOW_H_

#include "CCowboy.h"
#include "WWindow.h"

class Cowboy_window : public CCowboy, public WWindow {
public:
	void cow_draw() override;
	void win_draw() override;
};

#endif /* COWBOYWINDOW_H_ */

/*
 * Window.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "Stdinterface.h"
#include <string>
using std::string;

class Window : public Std_interface {
public:
	Window(string n) : name{n} { }
	void start();
	void suspend();
	void resume();
	void quit();
	void full_size();
	void small();
private:
	string name;
};

#endif /* WINDOW_H_ */

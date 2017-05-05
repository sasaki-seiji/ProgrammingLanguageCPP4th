/*
 * Window.h
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#ifndef WINDOW_H_
#define WINDOW_H_

struct Color {
	unsigned char r,g,b;
};

class Window {
public:
	virtual void set_color(Color) = 0;
	virtual void prompt() = 0;
	virtual ~Window() { }
};

#endif /* WINDOW_H_ */

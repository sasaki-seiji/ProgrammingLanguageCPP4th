/*
 * Displayed.h
 *
 *  Created on: 2016/08/29
 *      Author: sasaki
 */

#ifndef DISPLAYED_H_
#define DISPLAYED_H_

class Displayed {
public:
	virtual void draw() = 0;
};

void highlight(Displayed*);

#endif /* DISPLAYED_H_ */

/*
 * Ivalmaker.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef IVALMAKER_H_
#define IVALMAKER_H_

class Ival_dial;
class Popup_ival_slider;

class Ival_maker {
public:
	virtual Ival_dial* dial(int, int) = 0;
	virtual Popup_ival_slider* popup_ival_slider(int, int) = 0;

	virtual ~Ival_maker() { }
};

#endif /* IVALMAKER_H_ */

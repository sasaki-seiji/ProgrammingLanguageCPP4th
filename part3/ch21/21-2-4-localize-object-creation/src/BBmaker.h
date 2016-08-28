/*
 * BBmaker.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef BBMAKER_H_
#define BBMAKER_H_

#include "Ivalmaker.h"

class BB_maker : public Ival_maker {
public:
	Ival_dial* dial(int, int) override;
	Popup_ival_slider* popup_ival_slider(int, int) override;
};

#endif /* BBMAKER_H_ */

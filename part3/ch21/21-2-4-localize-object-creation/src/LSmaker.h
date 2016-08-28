/*
 * LSmaker.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSMAKER_H_
#define LSMAKER_H_

#include "Ivalmaker.h"

class LS_maker : public Ival_maker {
public:
	Ival_dial* dial(int, int) override;
	Popup_ival_slider* popup_ival_slider(int, int) override;
};

#endif /* LSMAKER_H_ */

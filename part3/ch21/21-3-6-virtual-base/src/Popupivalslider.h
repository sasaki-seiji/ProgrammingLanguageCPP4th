/*
 * Popupivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef POPUPIVALSLIDER_H_
#define POPUPIVALSLIDER_H_

#include "Ivalslider.h"

class Popup_ival_slider : public virtual Ival_slider {
public:
	virtual void popup() = 0 ;
	virtual void popdown() = 0 ;
};

#endif /* POPUPIVALSLIDER_H_ */

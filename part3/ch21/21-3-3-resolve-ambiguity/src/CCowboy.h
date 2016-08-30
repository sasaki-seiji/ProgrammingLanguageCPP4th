/*
 * CCowboy.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef CCOWBOY_H_
#define CCOWBOY_H_

#include "Cowboy.h"

class CCowboy : public Cowboy {
public:
	using Cowboy::Cowboy;
	virtual void cow_draw() = 0;
	void draw() override final { cow_draw(); }
};

#endif /* CCOWBOY_H_ */

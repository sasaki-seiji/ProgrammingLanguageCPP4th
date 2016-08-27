/*
 * Ivaldial.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALDIAL_H_
#define IVALDIAL_H_

#include "Ivalbox.h"

class Ival_dial : public Ival_box{
private:

public:
	Ival_dial(int, int);

	int get_value() override;
	void prompt() override;
};

#endif /* IVALDIAL_H_ */

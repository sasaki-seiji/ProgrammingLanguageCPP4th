/*
 * Receiver.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "Storable.h"

class Receiver : public Storable {
public:
	void write() override;
};

#endif /* RECEIVER_H_ */

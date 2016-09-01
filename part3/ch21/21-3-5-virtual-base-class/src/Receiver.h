/*
 * Receiver.h
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "Storable.h"

class Receiver : public virtual Storable {
public:
	Receiver(const string& name) : Storable{name} { }
	void write() override;
};

#endif /* RECEIVER_H_ */

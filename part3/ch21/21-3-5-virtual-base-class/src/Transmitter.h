/*
 * Transmitter.h
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

#include "Storable.h"

class Transmitter : public virtual Storable {
public:
	Transmitter(const string& name) : Storable{name} { }
	void write() override;
};

#endif /* TRANSMITTER_H_ */

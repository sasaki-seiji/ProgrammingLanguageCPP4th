/*
 * Transmitter.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

#include "Storable.h"

class Transmitter : public Storable {
public:
	void write() override;
};

#endif /* TRANSMITTER_H_ */

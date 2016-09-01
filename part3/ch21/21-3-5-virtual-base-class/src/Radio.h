/*
 * Radio.h
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#ifndef RADIO_H_
#define RADIO_H_

#include "Transmitter.h"
#include "Receiver.h"

class Radio : public Transmitter, public Receiver {
public:
	Radio(const string& name) : Storable{name}, Transmitter{name}, Receiver{name} { }
	void read() override;
	void write() override;
};

#endif /* RADIO_H_ */

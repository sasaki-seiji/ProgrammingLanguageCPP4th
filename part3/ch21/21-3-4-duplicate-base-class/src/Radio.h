/*
 * Radio.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef RADIO_H_
#define RADIO_H_

#include "Transmitter.h"
#include "Receiver.h"

class Radio : public Transmitter, public Receiver {
public:
	string get_file() override;
	void read() override;
	void write() override;
};

#endif /* RADIO_H_ */

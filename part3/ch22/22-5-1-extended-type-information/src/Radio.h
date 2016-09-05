/*
 * Radio.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef RADIO_H_
#define RADIO_H_

#include "Receiver.h"
#include "Transmitter.h"

// 2016.09.03: layout test
//class Radio : public Receiver, public Transmitter {
class Radio : public Transmitter, public Receiver {
public:
	int dummy{-100};
};

#endif /* RADIO_H_ */

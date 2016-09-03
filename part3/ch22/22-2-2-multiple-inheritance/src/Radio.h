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

class Radio : public Receiver, public Transmitter {
};

#endif /* RADIO_H_ */

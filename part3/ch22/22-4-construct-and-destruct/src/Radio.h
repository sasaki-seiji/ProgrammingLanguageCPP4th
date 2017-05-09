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
public:
	Radio() { virt_func1(); }
	~Radio() { virt_func2(); }
	void virt_func1() override { cout << "virt_func1() in Radio\n"; }
	void virt_func2() override { cout << "virt_func2() in Radio\n"; }
};

#endif /* RADIO_H_ */

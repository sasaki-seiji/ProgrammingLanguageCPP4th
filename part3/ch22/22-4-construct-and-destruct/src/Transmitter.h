/*
 * Transmitter.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

#include "Component.h"

class Transmitter : public Component {
public:
	Transmitter() { virt_func1(); }
	~Transmitter() { virt_func2(); }
	void virt_func1() override { cout << "virt_func1() in Transmitter\n"; }
	void virt_func2() override { cout << "virt_func2() in Transmitter\n"; }
};

#endif /* TRANSMITTER_H_ */

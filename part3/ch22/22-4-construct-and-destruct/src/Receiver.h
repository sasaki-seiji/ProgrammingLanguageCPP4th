/*
 * Receiver.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "Component.h"

class Receiver : public Component {
public:
	Receiver() { virt_func1(); }
	~Receiver() { virt_func2(); }
	void virt_func1() override { cout << "virt_func1() in Receiver\n"; }
	void virt_func2() override { cout << "virt_func2() in Receiver\n"; }
};

#endif /* RECEIVER_H_ */

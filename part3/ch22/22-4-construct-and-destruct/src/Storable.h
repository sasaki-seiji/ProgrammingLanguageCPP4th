/*
 * Storable.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef STORABLE_H_
#define STORABLE_H_

#include <iostream>
using namespace std;

class Storable {
public:
	Storable() { virt_func1(); }
	virtual ~Storable() { virt_func2(); }
	virtual void virt_func1() { cout << "virt_func1() in Storable\n"; }
	virtual void virt_func2() { cout << "virt_func2() in Storable\n"; }
};

#endif /* STORABLE_H_ */

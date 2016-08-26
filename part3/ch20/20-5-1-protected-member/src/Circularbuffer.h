/*
 * Circularbuffer.h
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include "Buffer.h"

class Circular_buffer : public Buffer {
public:
	void reallocate(char* p, int s);
public:
	Circular_buffer(int s) : Buffer{s} { }
};

#endif /* CIRCULARBUFFER_H_ */

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
private:
//	void reallocate(char* p, int s);
	void reallocate(int s);
public:
	Circular_buffer() : pos{0} { }
	void push_back(char c);
	int length() { return pos; }
private:
	int	pos;
};

#endif /* CIRCULARBUFFER_H_ */

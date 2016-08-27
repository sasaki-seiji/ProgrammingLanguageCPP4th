/*
 * Circularbuffer.cpp
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#include "Circularbuffer.h"

//void Circular_buffer::reallocate(char* p, int s)
void Circular_buffer::reallocate(int s)
{
	char* p = new char[s];
	int old_sz = size();
	for (int i=0; i!=old_sz; ++i)
		p[i] = access(i);

	set_buf(p, s);
}

void Circular_buffer::push_back(char c)
{
	if (pos >= size()) {
		int new_size = size()*2;
		reallocate(new_size);
	}

	access(pos++) = c;
}


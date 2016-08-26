/*
 * Circularbuffer.cpp
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#include "Circularbuffer.h"

void Circular_buffer::reallocate(char* p, int s)
{
	int old_sz = size();
	for (int i=0; i!=old_sz; ++i)
		p[i] = access(i);

	set_buf(p, s);
}

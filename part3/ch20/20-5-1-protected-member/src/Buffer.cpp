/*
 * Buffer.cpp
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#include "Buffer.h"

Buffer::Buffer(int s)
	:sz{s}
{
	buf = new char[sz];
}

void Buffer::set_buf(char* p, int s)
{
	delete[] buf;
	buf = p;
	sz = s;
}

char& Buffer::operator[](int i)
{
	if (i < 0 || sz <= i)
		throw Out_of_range{ };

	return buf[i];
}


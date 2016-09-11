/*
 * Allocator.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#include "Allocator.h"
#include <new>	// for bad_alloc

void* Your_allocator::allocate(size_t sz)
{
	if (free+sz > max)
		throw std::bad_alloc();

	char *p = &buf[free];
	free += sz;
	return p;
}


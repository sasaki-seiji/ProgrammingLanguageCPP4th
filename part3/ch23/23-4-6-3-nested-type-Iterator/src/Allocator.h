/*
 * Allocator.h
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <cstddef>
#include <cstdlib>
using namespace std;

class My_allocator {
public:
	void* allocate(size_t sz) { return ::operator new(sz); }
	void deallocate(void* p, size_t) { ::operator delete(p); }
};

class Your_allocator {
public:
	void* allocate(size_t sz) { return malloc(sz); }
	void deallocate(void* p, size_t) { free(p); }
};

#endif /* ALLOCATOR_H_ */

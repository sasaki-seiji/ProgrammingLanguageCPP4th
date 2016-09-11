/*
 * Allocator.h
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <cstddef>
using std::size_t;

class My_allocator {
public:
	void* allocate(size_t sz) { return new char[sz]; }
	void deallocate(void* p, size_t sz)
	{ delete [ ] static_cast<char*>(p); }
};

class Your_allocator {
	constexpr static int max = 1000;
	char buf[max];
	int free;
public:
	Your_allocator() : free{0} { }
	void* allocate(size_t);
	void deallocate(void*, size_t) { }
};

#endif /* ALLOCATOR_H_ */

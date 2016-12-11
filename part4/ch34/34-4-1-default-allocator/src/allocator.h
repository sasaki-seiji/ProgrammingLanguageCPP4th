/*
 * allocator.h
 *
 *  Created on: 2016/12/10
 *      Author: sasaki
 */

#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <cstdlib>

template<typename T>
struct Simple_alloc {
	using value_type = T;

	template<typename U>
		struct rebind { using other = Simple_alloc<U>; };

	Simple_alloc() { }

	T* allocate(std::size_t n)
		{ return reinterpret_cast<T*>(new char[n*sizeof(T)]); }
	void deallocate(T* p, std::size_t n)
		{ delete [] reinterpret_cast<char*>(p); }

	template<typename U, typename... Args>
		void construct(U* p, Args&&... args) { new(p) T{args...}; }
	template<typename U>
		void destroy(U* p) { p->~U(); }
};

class Arena {
	void* p;
	int s;

	int used;
public:
	Arena(void* pp, int ss) : p{pp}, s{ss}, used{0} { }

	void* get(size_t n);
	void release(void* p, size_t n) { }
};

inline void* Arena::get(size_t n)
{
	char* ret = reinterpret_cast<char*>(p) + used;
	if (used + n <= s) {
		used += n;
		return ret;
	}
	return nullptr;
}

template<typename T>
struct My_alloc {
	Arena& a;
	My_alloc(Arena& aa) : a(aa) { }
	My_alloc() { }

	using value_type = T;
	template<typename U>
		struct rebind { using other = My_alloc<U>; };

	// 2016.12.11 add: My_alloc<List> instance -> My_alloc<Link> instance
	template<typename U>
		My_alloc(const My_alloc<U>& alloc) : a{alloc.a} { }

	T* allocate(size_t n)
		{ return reinterpret_cast<T*>(a.get(n*sizeof(T))); }
	void deallocate(T* p, size_t n)
		{ a.release(p, n*sizeof(T)); }

	template<typename U, typename... Args>
		void construct(U* p, Args&&... args) { new(p) T{args...}; }
	template<typename U>
		void destroy(U* p) { p->~U(); }
};



#endif /* ALLOCATOR_H_ */

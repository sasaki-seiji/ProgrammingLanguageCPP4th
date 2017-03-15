/*
 * vector.h
 *
 *  Created on: 2016/05/21
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <memory>
using std::allocator;
using std::uninitialized_fill;

template<typename T, typename A = allocator<T>>
class Vector {
private:
	T* elem;
	T* space;
	T* last;
	A alloc;

public:
	using size_type = typename A::size_type;

	explicit Vector(size_type n, const T& val = T(), const A& = A());

	Vector(const Vector& a);
	Vector& operator=(const Vector& a);

	Vector(Vector&& a);
	Vector& operator=(Vector&& a);

	~Vector();

	size_type size() const { return space - elem; }
	size_type capacity() const { return last - elem; }
	void reserve(size_type n);

	void resize(size_type n, const T& = {});
	void push_back(const T&);

};

template<typename T, typename A>
Vector<T,A>::Vector(size_type n, const T& val, const A& a)
	:alloc{a}
{
	elem = alloc.allocate(n);
	try {
		uninitialized_fill(elem, elem+n, val);
		space = last = elem+n;
	}
	catch (...) {
		alloc.deallocate(elem, n);
		throw;
	}
}

template<typename T, typename A>
Vector<T,A>::~Vector()
{
	for (T* p = elem; p!=space; ++p)
		alloc.destroy(p);
	alloc.deallocate(elem, last-elem);
}

#endif /* VECTOR_H_ */

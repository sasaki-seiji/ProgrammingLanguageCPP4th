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

template<typename T, typename A = allocator<T>>
class vector {
private:
	T* elem;
	T* space;
	T* last;
	A alloc;

public:
	using size_type = typename A::size_type;

	explicit vector(size_type n, const T& val = T(), const A& = A());

	vector(const vector& a);
	vector& operator=(const vector& a);

	vector(vector&& a);
	vector& operator=(vector&& a);

	~vector();

	size_type size() const { return space - elem; }
	size_type capacity() const { return last - elem; }
	void reserve(size_type n);

	void resize(size_type n, const T& = {});
	void push_back(const T&);

};

template<typename T, typename A>
vector<T,A>::vector(size_type n, const T& val, const A& a)
	:alloc{a}
{
	elem = alloc.allocate(n);
	space = last = elem+n;
	for (T* p = elem; p!=space; ++p)
		//a.construct(p,val);
		alloc.construct(p,val);
}

template<typename T, typename A>
vector<T,A>::~vector()
{
	for (T* p = elem; p!=space; ++p)
		alloc.destroy(p);
	alloc.destroy(elem);
}

#endif /* VECTOR_H_ */

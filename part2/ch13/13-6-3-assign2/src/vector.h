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
using std::swap;
using std::uninitialized_copy;

template<typename T, typename A = allocator<T>>
struct vector_base {
	A alloc;
	T* elem;
	T* space;
	T* last;

	vector_base(const A& a, typename A::size_type n, typename A::size_type m = 0)
		:alloc{a}, elem{alloc.allocate(n+m)}, space{elem+n}, last{elem+n+m} { }
	~vector_base() { alloc.deallocate(elem, last-elem); }

	vector_base(const vector_base&) = delete;
	vector_base& operator=(const vector_base&) = delete;

	vector_base(vector_base&&);
	vector_base& operator=(vector_base&&);
};

template<typename T, typename A>
vector_base<T,A>::vector_base(vector_base&& a)
	: alloc{a.alloc},
	  elem{a.elem},
	  space{a.space},
	  last{a.last}
{
	a.elem = a.space = a.last = nullptr;
}

template<typename T, typename A>
vector_base<T,A>& vector_base<T,A>::operator=(vector_base&& a)
{
	// 2016.05.22 stack overflow
	//swap(*this, a);
	this->alloc = a.alloc;
	this->elem = a.elem;
	this->space = a.space;
	this->last = a.last;
	a.elem = a.space = a.last = nullptr;

	return *this;
}

template<typename T, typename A = allocator<T>>
class vector {
	vector_base<T,A> vb;
	void destroy_elements();

public:
	using size_type = typename A::size_type;

	explicit vector(size_type n, const T& val = T(), const A& = A());

	vector(const vector& a);
	vector& operator=(const vector& a);

	vector(vector&& a);
	vector& operator=(vector&& a);

	~vector() { destroy_elements(); }

	size_type size() const { return vb.space - vb.elem; }
	size_type capacity() const { return vb.last - vb.elem; }
	void reserve(size_type n);

	void resize(size_type n, const T& = {});
	void clear() { resize(0); }
	void push_back(const T&);

	// 2016.05.22 add
	T& operator[](size_type i) { return vb.elem[i]; }
	const T& operator[](size_type i) const { return vb.elem[i]; }
};

template<typename T, typename A>
void vector<T,A>::destroy_elements()
{
	for (T* p = vb.elem; p != vb.space; ++p)
		p->~T();
	vb.space = vb.elem;
}

template<typename T, typename A>
vector<T,A>::vector(size_type n, const T& val, const A& a)
	:vb{a,n}
{
	uninitialized_fill(vb.elem, vb.elem+n, val);
}

template<typename T, typename A>
vector<T,A>::vector(const vector<T,A>& a)
	:vb{a.vb.alloc, a.size()}
{
	//uninitialized_copy(a.begin(), a.end(), vb.elem);
	uninitialized_copy(a.vb.elem, a.vb.space, vb.elem);
}

template<typename T, typename A>
vector<T,A>::vector(vector&& a)
	:vb{move(a.vb)}
{
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& a)
{
	// 2016.05.22 not yet defined
	//clear();
	swap(vb, a.vb);
	return *this;
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector& a)
{
	vector temp {a};
	swap(*this, temp);
	return *this;
}
#endif /* VECTOR_H_ */

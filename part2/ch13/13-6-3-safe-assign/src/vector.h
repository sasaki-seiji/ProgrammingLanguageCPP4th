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
struct Vector_base {
	A alloc;
	T* elem;
	T* space;
	T* last;

	Vector_base(const A& a, typename A::size_type n, typename A::size_type m = 0)
		:alloc{a}, elem{alloc.allocate(n+m)}, space{elem+n}, last{elem+n+m} { }
	~Vector_base() { alloc.deallocate(elem, last-elem); }

	Vector_base(const Vector_base&) = delete;
	Vector_base& operator=(const Vector_base&) = delete;

	Vector_base(Vector_base&&);
	Vector_base& operator=(Vector_base&&);
};

template<typename T, typename A>
Vector_base<T,A>::Vector_base(Vector_base&& a)
	: alloc{a.alloc},
	  elem{a.elem},
	  space{a.space},
	  last{a.last}
{
	a.elem = a.space = a.last = nullptr;
}

template<typename T, typename A>
Vector_base<T,A>& Vector_base<T,A>::operator=(Vector_base&& a)
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
class Vector {
	Vector_base<T,A> vb;
	void destroy_elements();

public:
	using size_type = typename A::size_type;

	explicit Vector(size_type n, const T& val = T(), const A& = A());

	Vector(const Vector& a);
	Vector& operator=(const Vector& a);

	Vector(Vector&& a);
	Vector& operator=(Vector&& a);

	~Vector() { destroy_elements(); }

	size_type size() const { return vb.space - vb.elem; }
	size_type capacity() const { return vb.last - vb.elem; }
	void reserve(size_type n);

	void resize(size_type n, const T& = {});
	void clear() { resize(0); }
	void push_back(const T&);

	// 2016.05.22 add
	T& operator[](size_type i) { return vb.elem[i]; }
	const T& operator[](size_type i) const { return vb.elem[i]; }

	// 2016.05.22 add
	T* begin() { return vb.elem; }
	const T* begin() const { return vb.elem; }
	T* end() { return vb.space; }
	const T* end() const { return vb.space; }
};

template<typename T, typename A>
void Vector<T,A>::destroy_elements()
{
	for (T* p = vb.elem; p != vb.space; ++p)
		p->~T();
	vb.space = vb.elem;
}

template<typename T, typename A>
Vector<T,A>::Vector(size_type n, const T& val, const A& a)
	:vb{a,n}
{
	uninitialized_fill(vb.elem, vb.elem+n, val);
}

template<typename T, typename A>
Vector<T,A>::Vector(const Vector<T,A>& a)
	:vb{a.vb.alloc, a.size()}
{
	//uninitialized_copy(a.begin(), a.end(), vb.elem);
	uninitialized_copy(a.vb.elem, a.vb.space, vb.elem);
}

template<typename T, typename A>
Vector<T,A>::Vector(Vector&& a)
	:vb{move(a.vb)}
{
}

template<typename T, typename A>
Vector<T,A>& Vector<T,A>::operator=(Vector&& a)
{
	// 2016.05.22 not yet defined
	//clear();
	swap(vb, a.vb);
	return *this;
}

template<typename T, typename A>
Vector<T,A>& Vector<T,A>::operator=(const Vector& a)
{
	if (capacity() < a.size()) {
		Vector temp {a};
		swap(*this, temp);
		return *this;
	}
	if (this == &a) return *this;

	size_type sz = size();
	size_type asz = a.size();
	vb.alloc = a.vb.alloc;
	if (asz <= sz) {
		copy(a.begin(), a.begin() + asz, vb.elem);
		for (T* p = vb.elem + asz; p != vb.space; ++p)
			p->~T();
	}
	else {
		copy(a.begin(), a.begin() + sz, vb.elem);
		uninitialized_copy(a.begin() + sz, a.end(), vb.space);
	}
	vb.space = vb.elem + asz;
	return *this;
}

template<typename T, typename A>
void safe_assign(Vector<T,A>& a, const Vector<T,A>& b)
{
	Vector<T,A> temp{b};
	swap(a, temp);
}

template<typename T, typename A>
void safe_assign_by_value(Vector<T,A>& a, Vector<T,A> b)
{
	swap(a, b);
}

#endif /* VECTOR_H_ */

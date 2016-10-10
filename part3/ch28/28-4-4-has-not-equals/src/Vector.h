/*
 * Vector.h
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <initializer_list>
#include <algorithm>

template<typename T>
class Vector_iter {
	T* cur;
public:
	Vector_iter(T* p) : cur{p} { }
	Vector_iter() : cur{nullptr} { } // 2016.10.10 add
	T& operator*() { return *cur; }
	T* operator->() { return cur; }
#if 0
	bool operator==(Vector_iter other) { return cur == other.cur; }
	bool operator!=(Vector_iter other) { return !(*this==other); }
#else
	template<typename X>
	friend bool operator==(Vector_iter<X> a, Vector_iter<X> b);
#endif
	Vector_iter& operator++() { ++cur; return *this; }
};

template<typename T>
bool operator==(Vector_iter<T> a, Vector_iter<T> b)
{ return a.cur == b.cur; }

template<typename T>
bool operator!=(Vector_iter<T> a, Vector_iter<T> b)
{ return !(a==b); }

template<typename T>
class Vector {
	int sz;
	T* elem;
public:
	using value_type = T;
	using iterator = Vector_iter<T>;

	Vector(std::initializer_list<T>);

	Vector_iter<T> begin() { return Vector_iter<T>(elem); }
	Vector_iter<T> end() { return Vector_iter<T>(elem+sz); }
};

template<typename T>
Vector<T>::Vector(std::initializer_list<T> il)
	: sz{il.size()}, elem{new T[sz]}
{
	std::copy(il.begin(), il.end(), elem);
}
#endif /* VECTOR_H_ */

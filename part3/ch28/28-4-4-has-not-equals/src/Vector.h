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

	// 2016.10.10 add const
	bool operator==(Vector_iter other) const { return cur == other.cur; }
	bool operator!=(Vector_iter other) const { return !(*this==other); }

	Vector_iter& operator++() { ++cur; return *this; }
};

template<typename T>
class Vector {
	size_t sz;
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

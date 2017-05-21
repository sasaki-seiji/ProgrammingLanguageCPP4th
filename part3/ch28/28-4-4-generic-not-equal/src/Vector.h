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
class Vector {
	size_t sz;
	T* elem;
public:
	using value_type = T;
	using iterator = T*;

	Vector(std::initializer_list<T>);
	~Vector() { delete [] elem; }

	iterator begin() { return elem; }
	iterator end() { return elem+sz; }
};

template<typename T>
Vector<T>::Vector(std::initializer_list<T> il)
	: sz{il.size()}, elem{new T[sz]}
{
	std::copy(il.begin(), il.end(), elem);
}
#endif /* VECTOR_H_ */

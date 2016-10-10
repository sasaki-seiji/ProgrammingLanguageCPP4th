/*
 * Vector2.h
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_


#include <initializer_list>
#include <algorithm>
#include <iostream>

template<typename T>
class Vector2_iter {
	T* cur;
public:
	Vector2_iter(T* p) : cur{p} { }
	Vector2_iter() : cur{nullptr} { } // 2016.10.10 add
	T& operator*() { return *cur; }
	T* operator->() { return cur; }

	// 2016.10.10 add const
	bool operator==(Vector2_iter other) const
	{
		return cur == other.cur;
	}

	Vector2_iter& operator++() { ++cur; return *this; }
};

template<typename T>
class Vector2 {
	int sz;
	T* elem;
public:
	using value_type = T;
	using iterator = Vector2_iter<T>;

	Vector2(std::initializer_list<T>);

	Vector2_iter<T> begin() { return Vector2_iter<T>(elem); }
	Vector2_iter<T> end() { return Vector2_iter<T>(elem+sz); }
};

template<typename T>
Vector2<T>::Vector2(std::initializer_list<T> il)
	: sz{il.size()}, elem{new T[sz]}
{
	std::copy(il.begin(), il.end(), elem);
}



#endif /* VECTOR2_H_ */

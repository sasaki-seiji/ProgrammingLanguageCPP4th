/*
 * vector.h
 *
 *  Created on: 2017/05/19
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "type_converter.h"
#include "input_iterator.h"
using namespace Estd;

#include <iostream>
using namespace std;

// original vector definition

template<typename T>
class vector1 {
public:
	vector1(size_t n, const T& val);
	template<typename Iter>
		vector1(Iter b, Iter e);
};

template<typename T>
vector1<T>::vector1(size_t n, const T& val)
{
	cout << "vector1<T>::vector1(size_t: " << n << ", const T&: " << val << ")\n";
}

template<typename T>
template<typename Iter>
vector1<T>::vector1(Iter b, Iter e)
{
	cout << "vector1<T>::vector1<Iter>(Iter,Iter)\n";
}

// vector definition using enable_if

template<typename T>
class vector2 {
public:
	using iterator = T* ;

	vector2(size_t n, const T& val);

	template<typename Iter, typename =Enable_if<Input_iterator<Iter>()>>
		vector2(Iter b, Iter e);
};

template<typename T>
vector2<T>::vector2(size_t n, const T& val)
{
	cout << "vector2<T>::vector2(size_t: " << n << ", const T&: " << val << ")\n";
}

template<typename T>
template<typename Iter, typename>
vector2<T>::vector2(Iter b, Iter e)
{
	cout << "vector2<T>::vector2<Iter>(Iter,Iter)\n";
}


// vector definition using enable_if parameter

template<typename T>
class vector3 {
public:
	using iterator = T* ;

	vector3(size_t n, const T& val);

	template<typename Iter>
		vector3(Enable_if<Input_iterator<Iter>(),Iter> b, Iter e);
};

template<typename T>
vector3<T>::vector3(size_t n, const T& val)
{
	cout << "vector3<T>::vector3(size_t: " << n << ", const T&: " << val << ")\n";
}

template<typename T>
template<typename Iter>
vector3<T>::vector3(Enable_if<Input_iterator<Iter>(),Iter> b, Iter e)
{
	cout << "vector2<T>::vector2<Iter>(Iter,Iter)\n";
}

#endif /* VECTOR_H_ */

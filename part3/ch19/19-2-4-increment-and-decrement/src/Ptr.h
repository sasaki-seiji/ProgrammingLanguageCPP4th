/*
 * Ptr.h
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#ifndef PTR_H_
#define PTR_H_

#include <stdexcept>
using std::out_of_range;

template<typename T>
class Ptr {
	T* ptr;
	T* array;
	int sz;
public:
	template<int N> Ptr(T*p, T(&a)[N])	// array with size N
		: ptr{p}, array{&a[0]}, sz{N} { }
	Ptr(T* p, T* a, int s)				// array with size s
		: ptr{p}, array{a}, sz{s} { }
	Ptr(T* p)							// single object
		: ptr{p}, array{nullptr}, sz{0} { }

	Ptr& operator++();
	Ptr& operator--();
	Ptr operator++(int);
	Ptr operator--(int);

	T& operator*();

	T* operator->();
};

template<typename T>
inline Ptr<T>& Ptr<T>::operator++()
{
	if (sz == 0) throw out_of_range{ "increment to single object pointer : operator++()" };
	++ptr;
	return *this;
}

template<typename T>
inline Ptr<T> Ptr<T>::operator++(int)
{
	if (sz == 0) throw out_of_range{ "increment to single object pointer : operator++(int)" };
	Ptr<T> old {ptr,array,sz};
	++ptr;
	return old;
}

template<typename T>
inline Ptr<T>& Ptr<T>::operator--()
{
	if (sz == 0) throw out_of_range{ "decrement to single object pointer : operator--()" };
	--ptr;
	return *this;
}

template<typename T>
inline Ptr<T> Ptr<T>::operator--(int)
{
	if (sz == 0) throw out_of_range{ "decrement to single object pointer : operator--(int)" };
	Ptr<T> old {ptr,array,sz};
	--ptr;
	return old;
}

template<typename T>
inline T& Ptr<T>::operator*()
{
	if (sz==0) return *ptr;

	if (ptr<array || ptr>=&array[sz]) throw out_of_range{ "out of array access: operator*()" };
	return *ptr;
}

template<typename T>
inline T* Ptr<T>::operator->()
{
	if (sz==0) return ptr;

	if (ptr<array || ptr>=&array[sz]) throw out_of_range{ "out of array access: operator->()" };
	return ptr;
}

#endif /* PTR_H_ */

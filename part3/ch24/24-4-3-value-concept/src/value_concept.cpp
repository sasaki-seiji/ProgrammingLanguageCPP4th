/*
 * value_concept.cpp
 *
 *  Created on: 2016/10/24
 *      Author: sasaki
 */

#include "regular.h"
using namespace Estd;

#include <iostream>
using namespace std;

template<int N>
constexpr bool Small_size()
{
	return N<=8;
}

constexpr int stack_limit = 2048;

template<typename T, int N>
constexpr bool Stackable()
{
	return Regular<T>() && sizeof(T)*N <= stack_limit;
}

template<typename T, int N>
struct Buffer {
	T buf[N];
};

template<typename T, int N>
void fct()
{
	cout << "-- fct<T,N>() --\n";

	static_assert(Stackable<T,N>(), "fct() buffer won't fit on stack");
	Buffer<T,N> buf;
	buf.buf[0] = T{};
	cout << "buf.buf[0]: " << buf.buf[0] << '\n';
}

// add main

int main()
{
	cout << boolalpha;
	cout << "Small_size<4>(): " << Small_size<4>() << '\n';
	cout << "Small_size<10>(): " << Small_size<10>() << '\n';

	fct<int,512>();
	//fct<int,1024>();
		// error: static assertion failed: fct() buffer won't fit on stack
}

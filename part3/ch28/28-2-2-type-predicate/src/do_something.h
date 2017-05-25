/*
 * do_something.h
 *
 *  Created on: 2017/05/25
 *      Author: sasaki
 */

#ifndef DO_SOMETHING_H_
#define DO_SOMETHING_H_

#include "objholder.h"
#include <type_traits>
#include <typeinfo>
#include <iostream>

template<bool B, typename T, typename F>
using Conditional = typename std::conditional<B,T,F>::type;

template<typename T>
void do_something()
{
	Conditional<(std::is_pod<T>()),On_heap<T>,Scoped<T>> x;

	std::cout << "do_something1 - typeid(x).name(): " << typeid(x).name() << '\n';
}

template<typename T>
constexpr bool Is_pod()
{
	return std::is_pod<T>::value;
}

template<typename T>
void do_something2()
{
	Conditional<Is_pod<T>(),On_heap<T>,Scoped<T>> x;

	std::cout << "do_something2 - typeid(x).name(): " << typeid(x).name() << '\n';
}




#endif /* DO_SOMETHING_H_ */

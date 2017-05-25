/*
 * case_not_to_utilize_alias.cpp
 *
 *  Created on: 2016/10/04
 *      Author: sasaki
 */

#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <string>
using namespace std;

struct Error { };

// (1)original
template<typename T>
using Make_unsigned_for_integral = typename conditional<
		is_integral<T>::value,
		typename make_unsigned<T>::type,
		Error
	>::type;

Make_unsigned_for_integral<int> u1;
//Make_unsigned_for_integral<string> s1;
	// error: invalid use of incomplete type ‘class std::__make_unsigned_selector<std::__cxx11::basic_string<char>, false, false>’

// (2)template alias

template<typename T>
using Make_unsigned = typename make_unsigned<T>::type;

template<typename T>
using Make_unsigned_for_integral2 = typename conditional<
		is_integral<T>::value,
		Make_unsigned<T>,
		Error
	>::type;

Make_unsigned_for_integral2<int> u2;
//Make_unsigned_for_integral2<string> s2;
	// error: invalid use of incomplete type ‘class std::__make_unsigned_selector<std::__cxx11::basic_string<char>, false, false>’

// (3)Delay evaluation

template<template<typename...> class F, typename... Args>
using Delay = F<Args...>;

template<typename T>
using Make_unsigned_for_integral3 = typename conditional<
		is_integral<T>::value,
		Delay<Make_unsigned,T>,
		Error
	>::type;

Make_unsigned_for_integral3<int> u3;
//Make_unsigned_for_integral3<string> s3;
	// error: invalid use of incomplete type ‘class std::__make_unsigned_selector<std::__cxx11::basic_string<char>, false, false>’

// add main

int main()
{
	cout << "typeid(u1).name(): " << typeid(u1).name() << '\n';
	cout << "typeid(u2).name(): " << typeid(u2).name() << '\n';
	cout << "typeid(u3).name(): " << typeid(u3).name() << '\n';
}

/*
 * utilize_enable_if.cpp
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

#include "etypetraits.h"
using namespace Estd;

#include <cstddef>
#include <iostream>
#include <array>
#include <string>
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
	cout << "vector1<T>::vector<Iter>(Iter,Iter)\n";
}

vector1<int> v1(10,20);

// vector definition using enable_if

template<typename T>
class vector2 {
public:
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

vector2<int> v2(10,20);


// vector definition using enable_if parameter

template<typename T>
class vector3 {
public:
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

vector3<int> v3(10,20);

// non template function

constexpr int version2_2_3 = 223;
constexpr int config = 215;

struct My_struct { };

#if 0
Enable_if<(version2_2_3<config),My_struct>* make_default()
{
	return new My_struct{};
}
#endif
//error: no type named 'type' in 'struct std::enable_if<false, My_struct>'

template<typename T>
void f(const T& x)
{
	//Enable_if<!(20<sizeof(T)),T> tmp = x;
		// error: no type named 'type' in 'struct std::enable_if<false, std::array<std::__cxx11::basic_string<char>, 10ull> >'
	Enable_if<(20<sizeof(T)),T&> tmp = *new T{x};
}

// add main

int main()
{
	array<string, 10> arr;
	f(arr);
}

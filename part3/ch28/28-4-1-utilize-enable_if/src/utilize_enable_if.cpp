/*
 * utilize_enable_if.cpp
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

#include "vector.h"

#include <list>
#include <iostream>
#include <array>
#include <string>
using namespace std;

vector1<int> v1(10,20);
vector2<int> v2(10,20);
vector3<int> v3(10,20);

list<int> li = {1,2,3,4,5,6,7,8,9};

vector1<int> v12(li.begin(),li.end());
vector2<int> v22(li.begin(),li.end());
vector3<int> v32(li.begin(),li.end());

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
	cout << "-- f(const T&) --\n";

	//Enable_if<!(20<sizeof(T)),T> tmp = x;
		// error: no type named 'type' in 'struct std::enable_if<false, std::array<std::__cxx11::basic_string<char>, 10ull> >'
	Enable_if<(20<sizeof(T)),T&> tmp = *new T{x};

	cout << "sizeof(tmp) = " << sizeof(tmp) << endl;
	delete &tmp;
}

// add main

int main()
{
	array<string, 10> arr;
	f(arr);
}

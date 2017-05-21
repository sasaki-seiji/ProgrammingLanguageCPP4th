/*
 * usecase_of_enable_if.cpp
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

int f(int i); // put this before the following #include
#include "has_f.h"

#include "type_converter.h" // for Enable_if
using namespace Estd;

#include <iostream>
using namespace std;

template<typename T>
class X {
public:
	template<typename U=T>
	Enable_if<Has_f<U>()> use_f(const U& t)
	{
		f(t);
	}
};

int f(int i)
{
	cout << "f(int)\n";
	return i;
}

// add main

int main()
{
	cout << boolalpha;

	X<int> xi;
	cout << "Has_f<int>(): " << Has_f<int>() << endl;
	xi.use_f(10);

	X<string> xs;
	cout << "Has_f<string>(): " << Has_f<string>() << endl;
	//xs.use_f("string");
		// error: no matching function for call to 'X<std::__cxx11::basic_string<char> >::use_f(const char [7])'
}

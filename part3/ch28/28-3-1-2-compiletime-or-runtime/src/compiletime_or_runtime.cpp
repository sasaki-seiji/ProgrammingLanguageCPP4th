/*
 * compiletime_or_runtime.cpp
 *
 *  Created on: 2016/10/06
 *      Author: sasaki
 */

#include "type_converter.h" // for Conditional
#include "type_property_predicate.h" // for Is_polymorphic
using namespace Estd;

#include <iostream>
using namespace std;


struct Square {
	constexpr int operator()(int i) { return i*i; }
};

struct Cube {
	constexpr int operator()(int i) { return i*i*i; }
};

template<typename T>
constexpr bool My_cond()
{
	return Is_polymorphic<T>();
}

struct X { };

// add main
int main()
{
	if (My_cond<X>())
		using Type = Square;
	else
		using Type = Cube;

	//Type x1;
		// error: 'Type' was not declared in this scope

	auto x2 = Conditional<(My_cond<X>()),Square,Cube>{}(99);
	cout << "x2: " << x2 << '\n';

	//auto x3 = ((My_cond<X>())?Square:Cube){}(99);
		// error: expected primary-expression before ':' token

	//auto x4 = ((My_cond<X>())?Square{}:Cube{})(99);
		// error: operands to ?: have different types 'Square' and 'Cube'

	auto x5 = (My_cond<X>())?Square{}(99):Cube{}(99);
	cout << "x5: " << x5 << '\n';
}


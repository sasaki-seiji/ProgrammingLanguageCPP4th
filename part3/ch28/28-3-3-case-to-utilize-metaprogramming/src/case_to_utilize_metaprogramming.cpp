/*
 * compiletime_or_runtime.cpp
 *
 *  Created on: 2016/10/06
 *      Author: sasaki
 */

#include "type_property_predicate.h"
using namespace Estd;

#include <type_traits>
#include <iostream>
using namespace std;

#define IF(c,x,y) typename std::conditional<(c),x,y>::type

struct Square {
	constexpr int operator()(int i) { return i*i; }
};

struct Cube {
	constexpr int operator()(int i) { return i*i*i; }
};

struct X {
	int x;
};

// add main
int main()
{
	IF(Is_polymorphic<X>(),Cube,Square) z;
	cout << "z(99): " << z(99) << '\n';

	typename std::conditional<Is_pod<X>(),Cube,Square>::type z2;
	cout << "z2(99): " << z2(99) << '\n';
}


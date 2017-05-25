/*
 * select_function.cpp
 *
 *  Created on: 2016/10/05
 *      Author: sasaki
 */

#include "type_converter.h"
#include "type_property_predicate.h"
using namespace Estd;

#include <iostream>
#include <type_traits>
using namespace std;

struct X {
	void operator()(int x) { cout << "X" << x << "!\n"; }
	virtual ~X() { }
};

struct Y {
	void operator()(int x) { cout << "Y" << x << "!\n"; }
	virtual ~Y() { }
};

void f()
{
	Conditional<(sizeof(int)>4),X,Y>{}(7);

	using Z = Conditional<(Is_polymorphic<X>()),X,Y>;
	Z zz;
	zz(7);
}

// add main

int main()
{
	f();
}

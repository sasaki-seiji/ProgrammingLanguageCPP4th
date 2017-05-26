/*
 * conditional.cpp
 *
 *  Created on: 2016/10/06
 *      Author: sasaki
 */

#include "my_conditional.h"

#include "type_property_predicate.h"
using namespace Estd;

#include <type_traits>
#include <typeinfo>
#include <iostream>
using namespace std;


struct X { };
struct Y { };

struct Z {
	virtual ~Z() { }
};

typename my_conditional<(std::is_polymorphic<X>::value),X,Y>::type z1;
typename my_conditional<(std::is_polymorphic<Z>::value),X,Y>::type z2;

My_conditional<(Is_polymorphic<X>()),X,Y> z3;
My_conditional<(Is_polymorphic<Z>()),X,Y> z4;

// add main

int main()
{
	cout << "typeid(z1).name(): " << typeid(z1).name() << '\n';
	cout << "typeid(z2).name(): " << typeid(z2).name() << '\n';
	cout << "typeid(z3).name(): " << typeid(z3).name() << '\n';
	cout << "typeid(z4).name(): " << typeid(z4).name() << '\n';
}


/*
 * conditional.cpp
 *
 *  Created on: 2016/10/06
 *      Author: sasaki
 */

#include <type_traits>
#include <typeinfo>
#include <iostream>
using namespace std;


template<bool C, typename T, typename F>
struct my_conditional {
	using type = T;
};

template<typename T, typename F>
struct my_conditional<false,T,F> {
	using type = F;
};

struct X { };
struct Y { };

struct Z {
	virtual ~Z() { }
};

typename my_conditional<(std::is_polymorphic<X>::value),X,Y>::type z1;
typename my_conditional<(std::is_polymorphic<Z>::value),X,Y>::type z2;

template<bool B, typename T, typename F>
using My_conditional = typename my_conditional<B,T,F>::type;

template<typename T>
constexpr bool Is_polymorphic()
{
	return std::is_polymorphic<T>::value;
}

My_conditional<(Is_polymorphic<X>()),X,Y> z3;
My_conditional<(Is_polymorphic<Z>()),X,Y> z4;

// add main

int main()
{
	cout << "typeid(z1).name: " << typeid(z1).name() << '\n';
	cout << "typeid(z2).name: " << typeid(z2).name() << '\n';
	cout << "typeid(z3).name: " << typeid(z3).name() << '\n';
	cout << "typeid(z4).name: " << typeid(z4).name() << '\n';
}


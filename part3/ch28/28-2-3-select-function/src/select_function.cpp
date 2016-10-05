/*
 * select_function.cpp
 *
 *  Created on: 2016/10/05
 *      Author: sasaki
 */

#include <iostream>
#include <type_traits>
using namespace std;

struct X {
	void operator()(int x) { cout << "X" << x << "!\n"; }
};

struct Y {
	void operator()(int x) { cout << "Y" << x << "!\n"; }
};

template<bool B, typename T, typename F>
using Conditional = typename conditional<B,T,F>::type;

template<typename T>
constexpr bool Is_polymorphic()
{
	return is_polymorphic<T>::value;
}

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

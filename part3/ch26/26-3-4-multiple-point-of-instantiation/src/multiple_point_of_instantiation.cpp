/*
 * multiple_point_of_instantiation.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(int i) { cout << "::f(int: " << i << ")\n"; }

namespace N {
	class X { };
	char g(X x,int i)
	{ cout << "N::g(X,int:" << i << ")\n"; return i; }
}

template<typename T>
char ff(T t, double d)
{
	f(d);
	return g(t,d);
}

auto x1 = ff(N::X{}, 1.1);

namespace N {
	double g(X x,double d)
	{ cout << "N::g(X,double:" << d << ")\n"; return d; }
}

auto x2 = ff(N::X{}, 2.2);


// add main

int main()
{
	cout << "x1: " << (int)x1 << '\n';
	cout << "x2: " << (int)x2 << '\n';
}

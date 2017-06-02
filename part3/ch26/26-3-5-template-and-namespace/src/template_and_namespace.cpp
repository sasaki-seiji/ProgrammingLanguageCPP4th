/*
 * template_and_namespace.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

namespace N {
	class A { };
	char f(A) { cout << "N::f(A)\n"; return 'A'; }
}

char f(int i) { cout << "::f(int:" << i << ")\n"; return 'A'+i; }

template<typename T>
char g(T t)
{
	return f(t);
}

char f(double d) { cout << "::f(double:" << d << ")\n"; return d; }

char c1 = g(N::A());
char c2 = g(2);
char c3 = g(2.1);


// add main

int main()
{
	cout << "c1: " << c1 << '\n';
	cout << "c2: " << c2 << '\n';
	cout << "c3: " << c3 << '\n';
}


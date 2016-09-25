/*
 * base_depend_template.cpp
 *
 *  Created on: 2016/09/25
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void g(int) { cout << "::g(int)\n"; }

struct B {
	void g(char) { cout << "B::g(char)\n"; }
	void h(char) { cout << "B::h(char)\n"; }
};

template<typename T>
class X : public T {
public:
	void f()
	{
		g(2);
	}
};

void h(X<B> x)
{
	x.f();
}

// add main

int main()
{
	X<B> x;
	h(x);
}



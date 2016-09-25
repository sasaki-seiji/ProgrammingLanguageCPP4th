/*
 * explicit_dependency.cpp
 *
 *  Created on: 2016/09/25
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void g(int) { cout << "::g(int)\n"; }
void g2(int) { cout << "::g2(int)\n"; }

struct B {
	using Type = int;
	void g(char) { cout << "B::g(char)\n"; }
	void g2(char) { cout << "B::g2(char)\n"; }
};

template<typename T>
class X : public T {
public:
	typename T::Type m;
	//Type m2;
		// error: 'Type' does not name a type

	using T::g2;

	void f()
	{
		this->g(2);
		g(2);
		g2(2);
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

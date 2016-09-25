/*
 * base_independ_template.cpp
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
class X : public B {
public:
	void h(int) { cout << "X<>::h(int)\n"; }
	void f()
	{
		g(2);
		h(2);
	}
};


// add main

int main()
{
	X<int> x;
	x.f();
}


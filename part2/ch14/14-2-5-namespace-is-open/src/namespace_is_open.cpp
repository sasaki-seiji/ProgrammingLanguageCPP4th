/*
 * namespace_is_open.cpp
 *
 *  Created on: 2016/05/23
 *      Author: sasaki
 */

// header file
namespace A {
	int f();
}

namespace A {
	int g();
}

namespace Mine {
	void mf();
}

void yf();

namespace Mine {
	void mg();
}

// use functions
int main()
{
	A::f();
	A::g();
	Mine::mf();
	yf();
	Mine::mg();
}

// function definitions
#include <iostream>
using namespace std;

int A::f() { cout << "A::f()\n"; return 0; }
int A::g() { cout << "A::g()\n"; return 0; }

void Mine::mf() { cout << "Mine::mf()\n"; }
void Mine::mg() { cout << "Mine::mg()\n"; }

void yf() { cout << "::yf()\n"; }


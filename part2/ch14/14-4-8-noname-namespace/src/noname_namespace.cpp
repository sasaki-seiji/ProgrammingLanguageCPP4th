/*
 * noname-namespace.cpp
 *
 *  Created on: 2016/05/28
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

namespace {
	int a;
	void f() { cout << "f()\n"; }
	int g() { cout << "g()\n"; return 1; }
}

int main()
{
	f();
	g();

	a = 2;
	cout << "a: " << a << '\n';
}

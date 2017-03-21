/*
 * nested_namespace.cpp
 *
 *  Created on: 2016/05/28
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void h();

namespace X {
	void g();

	namespace Y {
		void f();
		void ff();
	}
}

void X::Y::ff()
{
	cout << "X::Y::ff()\n";

	f(); g(); h();
}

void X::g()
{
	cout << "X::g()\n";

	//f();
		// error: 'f' was not declared in this scope
	Y::f();
}

void h()
{
	cout << "::h()\n";

	//f();
		// error: 'f' was not declared in this scope
	//Y::f();
		// error: 'Y' has not been declared
	//X::f();
		// error: 'f' is not a member of 'X'
	X::Y::f();
}

int main()
{
	X::Y::ff();
}

// undefs
void X::Y::f()
{
	cout << "X::Y::f()\n";
}

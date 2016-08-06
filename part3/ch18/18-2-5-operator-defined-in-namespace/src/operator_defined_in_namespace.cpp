/*
 * operator_defined_in_namespace.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

struct X
{
	bool val;
	X(bool b): val{b} { };
};

X operator!(X x) { return X{!x.val} ; }

struct Z {
	Z operator!();
	X f(X x) { return !x; }
	int f(int x) { return !x; }
};

#include <string>
#include <iostream>

int main()
{
	const char* p = "Hello";
	std::string s = "world";
	std::cout << p << ", " << s << "!\n";

	X x{false};
	Z z;
	X x2 = z.f(x);
	std::cout << "x2 = z.f(x); x2.val: " << x2.val << '\n';
	int i = z.f(10);
	std::cout << "i = z.f(10); i: " << i << '\n';
}


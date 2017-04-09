/*
 * operator_defined_in_namespace.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include <string>
#include <iostream>

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

int main()
{
	const char* p = "Hello";
	std::string s = "world";
	std::cout << p << ", " << s << "!\n";

	std::cout << std::boolalpha;

	X x{false};
	std::cout << "X x{false}; x.val: " << x.val << '\n';

	Z z;
	X x2 = z.f(x);
	std::cout << "X x2 = z.f(x); x2.val: " << x2.val << '\n';

	int i = z.f(10);
	std::cout << "int i = z.f(10); i: " << i << '\n';
}


/*
 * default_operator.cpp
 *
 *  Created on: 2016/08/01
 *      Author: sasaki
 */

#include <string>
#include <iostream>
using namespace std;

struct S {
	string a;
	int b;
};

S f(S arg)
{
	S s0 {};
	cout << "S s0{}; s0.a = " << s0.a << ", s0.b = " << s0.b << '\n';

	S s1 {s0};
	cout << "S s1{s0}; s1.a = " << s1.a << ", s1.b = " << s1.b << '\n';

	s1 = arg;
	cout << "s1 = arg; s1.a = " << s1.a << ", s1.b = " << s1.b << '\n';

	return s1;
}

// add main

int main()
{
	S s = f(S{"string", 10});
	cout << "S s = f(S{\"string\",10}); s.a = " << s.a << ", s.b = " << s.b << '\n';

}

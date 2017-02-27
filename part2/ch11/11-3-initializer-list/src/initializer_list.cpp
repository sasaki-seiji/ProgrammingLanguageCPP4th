/*
 * initializer_list.cpp
 *
 *  Created on: 2016/05/01
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct S { int a, b; };
struct SS { double a, b; };

void f(S);

void g(S);
void g(SS);

void h()
{
	f({1,2});
	//g({1,2});
		// error: call of overloaded 'g(<brace-enclosed initializer list>)' is ambiguous

	g(S{1,2});
	g(SS{1,2});
}

int main()
{
	h();
}

// undefs
void f(S s)
{
	cout << "f(S)\n";
}

void g(S s)
{
	cout << "g(S)\n";
}

void g(SS s)
{
	cout << "g(SS)\n";
}

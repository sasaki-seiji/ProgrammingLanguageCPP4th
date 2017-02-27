/*
 * qualified_initializer_list.cpp
 *
 *  Created on: 2016/05/01
 *      Author: sasaki
 */

#include <complex>
#include <iostream>
using namespace std;

struct S { int a, b; };

void f()
{
	cout << "-- f() --\n";

	S v {7,8};
	v = S{7,8};
	S* p = new S{7,8};

	cout << "v.a = " << v.a << ", v.b = " << v.b << '\n';
	cout << "p->a = " << p->a << ", p->b = " << p->b << '\n';
}

template<typename T>
T square(T x)
{
	return x*x;
}

void f(int i)
{
	cout << "-- f(" << i << ") --\n";

	double d = square(double{i});
		// why? narrowing conversion of 'i' from 'int' to 'double' inside { } [-Wnarrowing]
		// -> see 11.5.1

	complex<double> z = square(complex<double>{i});
		// -> see 11.5.1

	cout << "d = " << d << '\n';
	cout << "z = " << z << '\n';
}
int main()
{
	f();
	f(12);
}


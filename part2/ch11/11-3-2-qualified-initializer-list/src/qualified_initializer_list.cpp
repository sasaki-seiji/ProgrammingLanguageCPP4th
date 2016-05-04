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
	S v {7,8};
	v = S{7,8};
	S* p = new S{7,8};

	cout << "v.a: " << v.a << ", vb: " << v.b << '\n';
	cout << "p->a: " << p->a << ", p->b: " << p->b << '\n';
}

template<typename T>
T square(T x)
{
	return x*x;
}

void f(int i)
{
	double d = square(double{i});
		// why? narrowing conversion of 'i' from 'int' to 'double' inside { } [-Wnarrowing]

	complex<double> z = square(complex<double>{i});

	cout << "d: " << d << '\n';
	cout << "z: " << z << '\n';
}
int main()
{
	f();
	f(12);
}


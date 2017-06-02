/*
 * point_of_instantiation_tempfunc.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

// point of instantiation

void g(int);

template<typename T>
void f(T a)
{
	g(a);
}

void h(int i)
{
	cout << "-- h(int: " << i << ") --\n";

	extern void g(double);
	f(i);
}

// indirect recursive call

void g2(int);

template<typename T>
void f2(T a)
{
	g2(a);
	if (a>1) h2(T(a-1));
}

enum Count { one=1, two, three };
void h2(Count i)
{
	cout << "-- h2(Count: " << i << ") --\n";

	f2(i);
}

// add undef

void g(int i) { cout << "g(int: " << i << ")\n"; }
void g2(int i) { cout << "g2(int: " << i << ")\n"; }

// add main

int main()
{
	h(12);
	h2(two);
}

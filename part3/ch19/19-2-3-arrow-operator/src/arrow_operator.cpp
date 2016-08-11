/*
 * arrow_operator.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct X {
	int m;
	X(int mm=0) :m{mm} { }
};

class Ptr {
	X *p;
public:
	Ptr(X* pp) : p{pp} { }
	X* operator->() { return p; }
};

void f(Ptr p)
{
	p->m = 7;
}

void g(Ptr p)
{
	// X* q1 = p->;
		// error: expected unqualified-id before ';' token
	X* q2 = p.operator->();

	q2->m = 20;
}


template<typename T>
class Ptr2 {
	T* p;
public:
	Ptr2(X* pp) : p{pp} { }
	T* operator->() { return p; }
	T& operator*() { return *p; }
	T& operator[](int i) { return p[i]; }
};

void h(Ptr2<X> p)
{
	cout << "-- h(Ptr2<X>):\n";

	cout << "p->m: " << p->m << '\n';
	cout << "(*p).m: " << (*p).m << '\n';
	cout << "p[0].m: " << p[0].m << '\n';
}

// add main

int main()
{
	X x{1};

	Ptr ptr{&x};
	f(ptr);

	cout << "x.m: " << x.m << '\n';

	g(ptr);
	cout << "x.m: " << x.m << '\n';

	Ptr2<X> ptr2{&x};
	h(ptr2);
}

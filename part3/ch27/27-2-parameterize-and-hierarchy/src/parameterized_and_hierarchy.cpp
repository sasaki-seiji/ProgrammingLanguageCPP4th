/*
 * parameterized_and_hierarchy.cpp
 *
 *  Created on: 2016/09/27
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

// parameterize

template<typename X>
class Ct {
	X mem;
public:
	X f();
	int g();
	void h(X);
};

struct A { };
struct B { };

template<>
class Ct<A> {
	A* mem;
public:
	A f();
	int g();
	void h(A);
	void k(int);
};

Ct<A> cta;
Ct<B> ctb ;

// add undef

template<typename X>
X Ct<X>::f()
{
	cout << "Ct<X>::f()\n";
	return X();
}

template<typename X>
int Ct<X>::g()
{
	cout << "Ct<X>::g()\n";
	return 10;
}

template<typename X>
void Ct<X>::h(X)
{
	cout << "Ct<X>::h(X)\n";
}

A Ct<A>::f()
{
	cout << "Ct<A>::f()\n";
	return A();
}

int Ct<A>::g()
{
	cout << "Ct<A>::g()\n";
	return 20;
}

void Ct<A>::h(A)
{
	cout << "Ct<A>::h(A)\n";
}

// inheritence

class X {

};

X x;

class Cx {
	X mem;
public:
	virtual X& f() = 0;
	virtual int g() = 0;
	virtual void h(X&) = 0;
};

class DA : public Cx {
public:
	X& f();
	int g();
	void h(X&);
};

class DB : public Cx {
public:
	X& f();
	int g();
	void h(X&);
	void k(int);
};

Cx& cxa {*new DA};
Cx& cxb {*new DB};

// add undef

X& DA::f()
{
	cout << "DA::f()\n";
	return x;
}

int DA::g()
{
	cout << "DA::g()\n";
	return 30;
}

void DA::h(X&)
{
	cout << "DA::h(X&)\n";
}

X& DB::f()
{
	cout << "DB::f()\n";
	return x;
}

int DB::g()
{
	cout << "DB::g()\n";
	return 40;
}

void DB::h(X&)
{
	cout << "DB::h(X&)\n";
}

// add main

int main()
{

	A a = cta.f();
	int i = cta.g();
	cta.h(a);

	B b = ctb.f();
	int j = ctb.g();
	ctb.h(b);

	X x = cxa.f();
	int k = cxa.g();
	cxa.h(x);

	x = cxb.f();
	int l = cxb.g();
	cxb.h(x);

}

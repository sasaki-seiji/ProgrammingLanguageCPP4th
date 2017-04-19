/*
 * using_base_member.cpp
 *
 *  Created on: 2016/08/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct Base {
	void f(int);
};
void Base::f(int x)
{
	cout << "Base::f(int: " << x << ")\n";
}


struct Derived : Base {
	void f(double);
};
void Derived::f(double x)
{
	cout << "Derived::f(double: " << x << ")\n";
}

void use(Derived d)
{
	cout << "-- use(Derived) --\n";

	d.f(1);
	Base& br = d;
	br.f(1);
}

struct D2 : Base {
	using Base::f;
	void f(double);
};

void use2(D2 d)
{
	cout << "-- use2(D2) --\n";

	d.f(1);
	Base& br = d;
	br.f(1);
}

struct B1 {
	void f(int);
};
void B1::f(int x)
{
	cout << "B1:f(int: " << x << ")\n";
}

struct B2 {
	void f(double);
};
void B2::f(double x)
{
	cout << "B2::f(double: " << x << ")\n";
}

struct D : B1, B2 {
	using B1::f;
	using B2::f;
	void f(char);
};
void D::f(char x)
{
	cout << "D::f(char: '" << x << "')\n";
}


void use(D d)
{
	cout << "-- use(D) --\n";

	d.f(1);
	d.f('a');
	d.f(1.0);
}


// add main

int main()
{
	Derived derived;
	use(derived);

	D2 d2;
	use2(d2);

	D d;
	use(d);
}

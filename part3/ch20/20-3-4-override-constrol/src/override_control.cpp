/*
 * override_control.cpp
 *
 *  Created on: 2016/08/22
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct B0 {
	void f(int) const;
	virtual void g(double);
};

struct B1 : B0 { };
struct B2 : B1 { };
struct B3 : B2 { };
struct B4 : B3 { };
struct B5 : B4 { };

struct D : B5 {
	void f(int) const;
	void g(int);
	virtual int h();
};

// add undef

void B0::f(int) const
{
	cout << "B0::f(int)\n";
}

void B0::g(double)
{
	cout << "B0::g(double)\n";
}

void D::f(int) const
{
	cout << "D::f(int)\n";
}

void D::g(int)
{
	cout << "D::g(int)\n";
}

int D::h()
{
	cout << "D::h()\n";
	return 10;
}
// add main

int main()
{
	D d;
	B0* b0 = &d;

	b0->f(10);
	b0->g(10);
}

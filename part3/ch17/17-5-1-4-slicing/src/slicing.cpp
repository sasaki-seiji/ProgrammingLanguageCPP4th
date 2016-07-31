/*
 * slicing.cpp
 *
 *  Created on: 2016/07/31
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct Base {
	int b;
	Base(const Base&);

	Base();
};

struct Derived : Base {
	int d;
	Derived(const Derived&);

	Derived();
};

void naive(Base* p)
{
	Base b2 = *p;
}

void user()
{
	Derived d;
	naive(&d);
	Base bb = d;
}

Base::Base()
	:b{0}
{
	cout << "Base::Base()\n";
}
Base::Base(const Base& x)
	:b{x.b}
{
	cout << "Base(const Base&)\n";
}

Derived::Derived()
	:Base{}, d{0}
{
	cout << "Derived::Derived(const Derived&)\n";
}
Derived::Derived(const Derived& x)
	:Base{x}, d{x.d}
{
	cout << "Derived::Derived(const Derived&)\n";
}

// add main

int main()
{
	user();
}

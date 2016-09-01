/*
 * construct_virtual_base_class.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct V {
	V(int i);
};

struct A {
	A();
};

struct B: virtual V, virtual A {
	B() : V{1} { cout << "B::B()\n"; }
};

class C : virtual V {
public:
	C(int i) : V{i} { cout << "C::C(" << i << ")\n"; }
};

class D : virtual public B, virtual public C {
public:
	//D() { /**/ }
		// error: no matching function for call to 'V::V()'
	//D(int i) : C{i} { /**/ }
		// error: no matching function for call to 'V::V()'
	D(int i, int j) : V{i}, C{j} { /**/ }
};

// add undefs

V::V(int i)
{
	cout << "V::V(" << i << ")\n";
}

A::A()
{
	cout << "A::A()\n";
}

// add main

int main()
{
	D d{10,20};
}

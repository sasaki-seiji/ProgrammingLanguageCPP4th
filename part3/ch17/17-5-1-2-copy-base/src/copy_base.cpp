/*
 * copy_base.cpp
 *
 *  Created on: 2016/07/31
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct B1 {
	B1();
	B1(const B1&);
};

struct B2 {
	B2(int);
	B2(const B2&);
};

struct D : B1, B2 {
	D(int i) :B1{}, B2{i}, m1{}, m2{2*i} { }
	D(const D& a) :B1(a), B2(a), m1{a.m1}, m2{a.m2} { }
	B1 m1;
	B2 m2;
};


D d {1};
D dd {d};

// add undef func

B1::B1()
{
	cout << "B1::B1()\n";
}

B1::B1(const B1&)
{
	cout << "B1::B1(const B1&)\n";
}

B2::B2(int i)
{
	cout << "B2::B2(" << i << ")\n";
}

B2::B2(const B2&)
{
	cout << "B2::B2(const B2&)\n";
}
// add main

int main()
{
}
